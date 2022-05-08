#include "Hashtable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#define LOAD_FACTOR_CUTOFF 0.75
#define RESIZE_FACTOR 2

uint64_t FNVHash64(unsigned char *buffer, unsigned int len) {
    // This code is adapted from code by Landon Curt Noll
    // and Bonelli Nicola:
    //
    // http://code.google.com/p/nicola-bonelli-repo/
    static const uint64_t FNV1_64_INIT = 0xcbf29ce484222325ULL;
    static const uint64_t FNV_64_PRIME = 0x100000001b3ULL;
    unsigned char *bp = (unsigned char *)buffer;
    unsigned char *be = bp + len;
    uint64_t hval = FNV1_64_INIT;
    /*
     * FNV-1a hash each octet of the buffer
     */
    while (bp < be) {
        /* xor the bottom with the current octet */
        hval ^= (uint64_t)*bp++;
        /* multiply by the 64 bit FNV magic prime mod 2^64 */
        hval *= FNV_64_PRIME;
    }
    /* return our new hash value */
    return hval;
}

uint64_t FNVHashInt64(uint64_t makehash) {
    unsigned char buf[8];
    int i;
    for (i = 0; i < 8; i++) {
        buf[i] = (unsigned char)(makehash & 0x00000000000000FFULL);
        makehash >>= 8;
    }
    return FNVHash64(buf, 8);
}

int NeedResize(Hashtable ht) {
    if (GetAlpha(ht) >= LOAD_FACTOR_CUTOFF) {
        return 1;
    }
    return 0;
}

void FreeKeyValuePairWithoutFreeingContent(void *kvpPtr) { free(kvpPtr); }

void ResizeHashtable(Hashtable ht) {
    int preBucketSize = ht->numBuckets;
    int newBucketSize = preBucketSize * RESIZE_FACTOR;
    ht->numBuckets = newBucketSize;
    LinkedList *newBuckets = malloc(newBucketSize * sizeof(LinkedList));
    assert(newBuckets != NULL);
    int i;
    for (i = 0; i < newBucketSize; i++) {
        newBuckets[i] = CreateLinkedList();
        assert(newBuckets[i] != NULL);
    }
    LinkedList *buckets = ht->buckets;
    HTKeyValue **kvpPtrPtr = malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    for (i = 0; i < preBucketSize; i++) {
        LLIter iter = CreateLLIter(buckets[i]);
        if (iter != NULL) {
            while (LLIterHasNext(iter)) {
                LLIterNext(iter);
                *kvpPtrPtr = NULL;
                LLIterGetPayload(iter, (void **)kvpPtrPtr);
                if (*kvpPtrPtr != NULL) {
                    uint64_t key = (*kvpPtrPtr)->key;
                    int newIndex = HashKeyToBucketNum(ht, key);
                    AppendLinkedList(newBuckets[newIndex], *kvpPtrPtr);
                }
            }
        }
        DestroyLinkedList(buckets[i], NULL);
	    DestroyLLIter(iter);
    }
    free(buckets);
    free(kvpPtrPtr);
    ht->buckets = newBuckets;
}

int HashKeyToBucketNum(Hashtable ht, uint64_t key) {
    uint64_t bucketSize = ht->numBuckets;
    double res = key % bucketSize;
    return (int)res;
}

double GetAlpha(Hashtable ht) {
    return (double)ht->numElements / ht->numBuckets;
}

Hashtable CreateHashtable(int numBuckets) {
    Hashtable ht = malloc(sizeof(struct hashtableInfo));
    assert(ht != NULL);
    LinkedList *buckets = malloc(numBuckets * sizeof(LinkedList));
    assert(buckets != NULL);
    int i;
    for (i = 0; i < numBuckets; i++) {
        buckets[i] = CreateLinkedList();
        assert(buckets[i] != NULL);
    }
    ht->numBuckets = numBuckets;
    ht->numElements = 0;
    ht->buckets = buckets;
    return ht;
}

void DestroyHashtable(Hashtable ht, LLPayloadFreeFnPtr value_free_function) {
    assert(ht != NULL);
    LinkedList *buckets = ht->buckets;
    int i;
    int numBuckets = ht->numBuckets;
    for (i = 0; i < numBuckets; i++) {
        DestroyLinkedList(buckets[i], value_free_function);
    }
    free(buckets);
    free(ht);
}

// Puts the given key value pair int the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
//   kvp: the key-value pair to put into the hashtable.
//
// Returns 0 if put is successful.
// Returns 1 on failure (e.g., no more memory).
// Returns 2 if the key is already in the hashtable.
int PutInHashtable(Hashtable ht, HTKeyValue *kvp) {
    assert(ht != NULL);
    assert(kvp != NULL);
    uint64_t key = kvp->key;
    int index = HashKeyToBucketNum(ht, key);
    LinkedList *buckets = ht->buckets;
    LLIter iter = CreateLLIter(buckets[index]);
    HTKeyValue **kvpPtrPtr = malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    if (iter != NULL) {
        while (LLIterHasNext(iter)) {
            LLIterNext(iter);
            *kvpPtrPtr = NULL;
            LLIterGetPayload(iter, (void **)kvpPtrPtr);
            if (*kvpPtrPtr != NULL && (*kvpPtrPtr)->key == key) {
                DestroyLLIter(iter);
                free(kvpPtrPtr);
                return 2;
            }
        }
    }
    DestroyLLIter(iter);
    free(kvpPtrPtr);
    if (AppendLinkedList(buckets[index], (void *)kvp) == 1) return 1;
    ht->numElements++;
    return 0;
}

// Looks up the given key in the hashtable.
// Returns the Key-Value pair in the provided result pointer.
//
// INPUT:
//   ht: the hashtable to lookup in
//   key: the key to lookup
//   result: If the key is in the hashtable, this is used
//      to return a pointer to a HTKeyValue to the caller.
//      Note, this HTKeyValue is still in the hashtable, so can't
//      be used to free the value.
//
// Returns 0 if the lookup was successful (and the result is valid).
// Returns -1 if the key was not found.
int LookupInHashtable(Hashtable ht, uint64_t key, HTKeyValue **result) {
    assert(ht != NULL);
    int index = HashKeyToBucketNum(ht, key);
    LinkedList *buckets = ht->buckets;
    LinkedList curList = buckets[index];
    assert(curList != NULL);
    if (curList->numElements == 0) return -1;
    LLIter iter = CreateLLIter(curList);
    HTKeyValue **kvpPtrPtr = (HTKeyValue **)malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    if (iter != NULL) {
        while (LLIterHasNext(iter)) {
            LLIterNext(iter);
            *kvpPtrPtr = NULL;
            LLIterGetPayload(iter, (void **)kvpPtrPtr);
            if (*kvpPtrPtr != NULL && (*kvpPtrPtr)->key == key) {
                DestroyLLIter(iter);
                *result = *kvpPtrPtr;
                free(kvpPtrPtr);
                return *result != NULL ? 0 : -1;
            }
        }
    }
    free(kvpPtrPtr);
    DestroyLLIter(iter);
    return -1;
}

// Replaces the value of a given key in the hashtable.
//
// INPUT:
//   ht: Hashtable to replace value
//   key: key of item to be replaced
//   newVal: new item to put in HT
//   oldVal: the HTKeyValue that was removed from the hashtable,
//      which allows the caller to free it as necessary.
//
// Returns 0 if successful (and oldVal is valid)
// Returns -1 if the key was not found in the hashtable (and oldval is invalic)
int ReplaceInHashtable(Hashtable ht, HTKeyValue *newVal, HTKeyValue **oldVal) {
    assert(ht != NULL);
    assert(newVal != NULL);
    LinkedList *buckets = ht->buckets;
    uint64_t key = newVal->key;
    int index = HashKeyToBucketNum(ht, key);
    LLIter iter = CreateLLIter(buckets[index]);
    HTKeyValue **kvpPtrPtr = (HTKeyValue **)malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    if (iter != NULL) {
        while (LLIterHasNext(iter)) {
            LLIterNext(iter);
            *kvpPtrPtr = NULL;
            LLIterGetPayload(iter, (void **)kvpPtrPtr);
            if (*kvpPtrPtr != NULL && (*kvpPtrPtr)->key == key) {
                *oldVal = (HTKeyValuePtr)(iter->curNode->payload);
                iter->curNode->payload = newVal;
                DestroyLLIter(iter);
                free(kvpPtrPtr);
                return *oldVal != NULL ? 0 : -1;
            }
        }
    }
    DestroyLLIter(iter);
    free(kvpPtrPtr);
    return -1;
}

// Removes the HTKeyValue with the given key from the
//  hashtable.
//
// INPUT:
//   ht: the hashtable
//   key: the key to remove
//   junkKVP: a pointer to the removed HTKeyValue, to
//     allow the value to be freed by the caller.
//
// Returns 0 if the key was found successfully (and junkKVP is valid)
// Returns -1 if the key was not found in the hashtable.
int RemoveFromHashtable(Hashtable ht, uint64_t key, HTKeyValue **junkKvp) {
    assert(ht != NULL);
    LinkedList *buckets = ht->buckets;
    int index = HashKeyToBucketNum(ht, key);
    LLIter iter = CreateLLIter(buckets[index]);
    HTKeyValue **kvpPtrPtr = (HTKeyValue **)malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    if (iter != NULL) {
        while (LLIterHasNext(iter)) {
            LLIterNext(iter);
            *kvpPtrPtr = NULL;
            LLIterGetPayload(iter, (void **)kvpPtrPtr);
            if (*kvpPtrPtr != NULL && (*kvpPtrPtr)->key == key) {
                *junkKvp = *kvpPtrPtr;
                LinkedListNodePtr junkNodePtr = iter->curNode;
                if (iter->curNode == iter->list->head) {
                    iter->list->head = iter->list->head->next;
                }
                if (iter->curNode->prev != NULL) {
                    iter->curNode->prev->next = iter->curNode->next;
                }
                if (iter->curNode->next != NULL) {
                    iter->curNode->next->prev = iter->curNode->prev;
                }

                iter->list->numElements--;
                free(junkNodePtr);
                ht->numElements--;
                DestroyLLIter(iter);
                free(kvpPtrPtr);
                return *junkKvp != NULL ? 0 : -1;
            }
        }
    }
    DestroyLLIter(iter);
    free(kvpPtrPtr);
    return -1;
}

int NumElemsInHashtable(Hashtable ht) {
    assert(ht != NULL);
    return ht->numElements;
}

int Remove(Hashtable ht, void *keyString, LLPayloadFreeFnPtr value_free_function) {
    if (keyString == NULL) return -1;
    unsigned int len = strlen((char *)keyString);
    unsigned char *buffer = malloc((len + 1) * sizeof(unsigned char));
    assert(buffer != NULL);
    strcpy((char *)buffer, (char *)keyString);
    uint64_t value = FNVHash64(buffer, len);
    uint64_t key = FNVHashInt64(value);
    free(buffer);
    HTKeyValue **junkKvp = (HTKeyValue **)malloc(sizeof(HTKeyValuePtr));
    int result = RemoveFromHashtable(ht, key, junkKvp);
    if (*junkKvp != NULL) {
        value_free_function((void *)*junkKvp);
    }
    free(junkKvp);
    return result;
}

int Put(Hashtable ht, void *keyString, void *payload) {
    unsigned int len = strlen((char *)keyString);
    unsigned char *buffer = malloc((len + 1) * sizeof(unsigned char));
    assert(buffer != NULL);
    strcpy((char *)buffer, (char *)keyString);
    uint64_t value = FNVHash64(buffer, len);
    uint64_t key = FNVHashInt64(value);
    free(buffer);
    HTKeyValuePtr newKvp = malloc(sizeof(HTKeyValue));
    assert(newKvp != NULL);
    newKvp->key = key;
    newKvp->value = payload;
    return PutInHashtable(ht, newKvp);
}

HTKeyValuePtr Get(Hashtable ht, void *keyString) {
    unsigned int len = strlen((char *)keyString);
    unsigned char *buffer = malloc((len + 1) * sizeof(unsigned char));
    assert(buffer != NULL);
    strcpy((char *)buffer, (char *)keyString);
    uint64_t value = FNVHash64(buffer, len);
    uint64_t key = FNVHashInt64(value);
    free(buffer);
    HTKeyValue **kvpPtrPtr = malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    *kvpPtrPtr = NULL;
    LookupInHashtable(ht, key, kvpPtrPtr);
    HTKeyValuePtr kvpPtr = *kvpPtrPtr;
    free(kvpPtrPtr);
    return kvpPtr;
}

int Contains(Hashtable ht, void *keyString) {
    unsigned int len = strlen((char *)keyString);
    unsigned char *buffer = malloc((len + 1) * sizeof(unsigned char));
    assert(buffer != NULL);
    strcpy((char *)buffer, (char *)keyString);
    uint64_t value = FNVHash64(buffer, len);
    uint64_t key = FNVHashInt64(value);
    free(buffer);
    HTKeyValue **kvpPtrPtr = malloc(sizeof(HTKeyValuePtr));
    assert(kvpPtrPtr != NULL);
    *kvpPtrPtr = NULL;
    int result = LookupInHashtable(ht, key, kvpPtrPtr);
    free(kvpPtrPtr);
    return result;
}

void FreeBucketList(void *payload) {
    HTKeyValuePtr kvpPtr = payload;
    LinkedList list = kvpPtr->value;
    DestroyLinkedList(list, FreeString);
    free(kvpPtr);
}

void FreeKeyValuePair(void *payload) {
    LinkedList list = ((HTKeyValuePtr)payload)->value;
    DestroyLinkedList(list, FreeString);
    free(payload);
}
