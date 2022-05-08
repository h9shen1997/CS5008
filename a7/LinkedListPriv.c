#include "LinkedListPriv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedListNodePtr CreateLinkedListNode(void* payload) {
    LinkedListNodePtr newNode = malloc(sizeof(LinkedListNode));
    assert(newNode != NULL);
    newNode->payload = payload;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void FreeString(void* payload) { free((char*)payload); }

int CompareString(const void* payloadA, const void* payloadB) {
    return strcmp((const char*)payloadA, (const char*)payloadB);
}
