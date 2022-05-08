#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hashtable.h"
#include "LinkedList.h"

int CompareChar(const void* a, const void* b) { return *(char*)a - *(char*)b; }

void ReadFromFileAndProcess(FILE* filePtr, Hashtable ht) {
    const char* filename = "words.txt";
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    filePtr = fopen(filename, "r");
    assert(filePtr != NULL);
    while ((read = getline(&line, &len, filePtr)) != -1) {
        char* keyString = malloc((len + 1) * sizeof(char));
        char* word = malloc((len + 1) * sizeof(char));
        strcpy(keyString, line);
        strcpy(word, line);
        keyString[strcspn(keyString, "\n")] = '\0';
        word[strcspn(word, "\n")] = '\0';
        qsort(keyString, strlen(keyString), sizeof(char), CompareChar);
        if (Contains(ht, keyString) == 0) {
            HTKeyValuePtr newVal = Get(ht, keyString);
            AppendLinkedList((LinkedList)(newVal->value), (void*)word);
        } else {
            LinkedList list = CreateLinkedList();
            AppendLinkedList(list, (void*)word);
            Put(ht, (void*)keyString, (void*)list);
        }
        free(keyString);
        if (NeedResize(ht)) {
            ResizeHashtable(ht);
        }
    }
    free(line);
    fclose(filePtr);
}

void PrintLinkedList(LinkedList list) {
    if (list == NULL || list->numElements == 0) return;
    LLIter iter = CreateLLIter(list);
    if (iter == NULL) return;
    while (LLIterHasNext(iter)) {
        LLIterNext(iter);
        printf("%s ", (char*)(iter->curNode->payload));
    }
    printf("\n");
    DestroyLLIter(iter);
}

void PrintAnagramHashtable(Hashtable ht) {
    LinkedList* buckets = ht->buckets;
    int numBuckets = ht->numBuckets;
    int i;
    for (i = 0; i < numBuckets; i++) {
        LLIter iter = CreateLLIter(buckets[i]);
        if (iter == NULL) {
            DestroyLLIter(iter);
            continue;
        }
        HTKeyValue** kvpPtrPtr = (HTKeyValue**)malloc(sizeof(HTKeyValuePtr));
        assert(kvpPtrPtr != NULL);
        *kvpPtrPtr = NULL;
        while (LLIterHasNext(iter)) {
            LLIterNext(iter);
            LLIterGetPayload(iter, (void**)kvpPtrPtr);
            if (*kvpPtrPtr == NULL) continue;
            LinkedList anagramList = (*kvpPtrPtr)->value;
            if (anagramList->numElements > 1) PrintLinkedList(anagramList);
        }
        DestroyLLIter(iter);
        free(kvpPtrPtr);
    }
}

int main() {
    printf("************Anagram Algorithm using Hashtable************\n");
    FILE* filePtr = NULL;
    Hashtable ht = CreateHashtable(10000);
    ReadFromFileAndProcess(filePtr, ht);
    PrintAnagramHashtable(ht);
    DestroyHashtable(ht, FreeBucketList);
}
