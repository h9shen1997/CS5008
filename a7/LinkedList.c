#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList CreateLinkedList() {
    LinkedList list = malloc(sizeof(struct ll_head));
    assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;
    list->numElements = 0;
    return list;
}

int DestroyLinkedList(LinkedList list, LLPayloadFreeFnPtr payloadFreeFunc) {
    if (list != NULL) {
        LinkedListNodePtr cur = list->head;
        while (cur != NULL) {
            LinkedListNodePtr next = cur->next;
            if (payloadFreeFunc != NULL) payloadFreeFunc(cur->payload);
            free(cur);
            cur = next;
        }
    }
    free(list);
    return 0;
}

unsigned int NumElementsInLinkedList(LinkedList list) {
    assert(list != NULL);
    return list->numElements;
}

int InsertLinkedList(LinkedList list, void* payload) {
    assert(list != NULL);
    LinkedListNodePtr newNode = CreateLinkedListNode(payload);
    assert(newNode != NULL);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->numElements++;
    return 0;
}

int PopLinkedList(LinkedList list, void** payload) {
    assert(list != NULL);
    if (list->head == NULL) return 1;
    LinkedListNodePtr head = list->head;
    *payload = head->payload;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    free(head);
    list->numElements--;
    return 0;
}

int AppendLinkedList(LinkedList list, void* payload) {
    assert(list != NULL);
    LinkedListNodePtr newNode = CreateLinkedListNode(payload);
    assert(newNode != NULL);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->numElements++;
    return 0;
}

int SliceLinkedList(LinkedList list, void** payload) {
    assert(list != NULL);
    if (list->tail == NULL) return 1;
    LinkedListNodePtr tail = list->tail;
    *payload = tail->payload;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    free(tail);
    list->numElements--;
    return 0;
}

LLIter CreateLLIter(LinkedList list) {
    assert(list != NULL);
    if (list->head == NULL) return NULL;
    LLIter iter = (LLIter)malloc(sizeof(LLIterSt));
    assert(iter != NULL);
    iter->list = list;
    iter->curNode = NULL;
    return iter;
}

int LLIterHasNext(LLIter iter) {
    assert(iter != NULL);
    if (iter->curNode == NULL) return iter->list->head != NULL;
    if (iter->curNode == iter->list->tail) return 0;
    return iter->curNode->next != NULL;
}

int LLIterHasPrev(LLIter iter) {
    assert(iter != NULL);
    if (iter->curNode == NULL) return iter->list->tail != NULL;
    if (iter->curNode == iter->list->head) return 0;
    return iter->curNode->prev != NULL;
}

int LLIterNext(LLIter iter) {
    assert(iter != NULL);
    if (iter->curNode == NULL) {
        iter->curNode = iter->list->head;
        return 1;
    }
    iter->curNode = iter->curNode->next;
    return 0;
}

int LLIterPrev(LLIter iter) {
    assert(iter != NULL);
    if (iter->curNode == NULL) {
        iter->curNode = iter->list->tail;
        return 1;
    }
    iter->curNode = iter->curNode->prev;
    return 0;
}

int DestroyLLIter(LLIter iter) {
    free(iter);
    return 0;
}

int LLIterGetPayload(LLIter iter, void** payload) {
    assert(iter != NULL);
    if (iter->curNode == NULL) return 1;
    *payload = iter->curNode->payload;
    return 0;
}

int LLIterDelete(LLIter iter, LLPayloadFreeFnPtr payloadFreeFunc) {
    assert(iter != NULL);
    if (iter->curNode == NULL) return 1;
    LinkedListNodePtr curNode = iter->curNode;
    LinkedList list = iter->list;
    void** payloadPtrPtr = malloc(sizeof(void*));
    if (curNode == list->tail) {
        SliceLinkedList(list, payloadPtrPtr);
        iter->curNode = list->tail;
    } else {
        if (curNode == list->head) {
            PopLinkedList(list, payloadPtrPtr);
            iter->curNode = list->head;
        } else {
            *payloadPtrPtr = curNode->payload;
            iter->curNode = curNode->next;
            if (curNode->prev != NULL) curNode->prev->next = curNode->next;
            if (curNode->next != NULL) curNode->next->prev = curNode->prev;
            free(curNode);
            list->numElements--;
        }
    }
    assert(*payloadPtrPtr != NULL);
    payloadFreeFunc(*payloadPtrPtr);
    if (iter->list->numElements == 0) {
        DestroyLLIter(iter);
        return 1;
    }
    return 0;
}

int LLIterInsertBefore(LLIter iter, void* payload) {
    assert(iter != NULL);
    assert(payload != NULL);
    LinkedListNodePtr curNode = iter->curNode;
    LinkedList list = iter->list;
    assert(curNode != NULL);
    assert(list != NULL);
    LinkedListNodePtr newNode = CreateLinkedListNode(payload);
    if (newNode == NULL) return 1;
    if (curNode == list->head) {
        InsertLinkedList(list, payload);
    } else {
        LinkedListNodePtr prevNode = curNode->prev;
        newNode->next = curNode;
        curNode->prev = newNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        list->numElements++;
    }
    return 0;
}