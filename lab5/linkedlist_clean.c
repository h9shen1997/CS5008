#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedListPtr CreateLinkedList() {
    LinkedListPtr list = (LinkedListPtr)malloc(sizeof(LinkedListPtr));
    if (list == NULL) {
        return NULL;
    }
    list->head = list->tail = NULL;
    list->num_elements = 0;
    return list;
}

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedList(LinkedListPtr list) {
    if (list == NULL || list->head == NULL) {
        return;
    }
    LinkedListNodePtr temp = list->head;
    while (temp != NULL) {
        LinkedListNodePtr next = temp->next;
        DestroyLinkedListNode(temp);
        temp = next;
    }
    free(list);
}

// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList
//
// Returns the number of elements in the list.
unsigned int NumberElementsInLinkedList(LinkedListPtr list) {
    if (list == NULL) {
        return EXIT_SUCCESS;
    }
    return list->num_elements;
}

// Adds an element to the head of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int InsertLinkedList(LinkedListPtr list, int data) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNode *newNode = CreateLinkedListNode(data);
    if (newNode == NULL) {
        return EXIT_FAILURE;
    }
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->num_elements++;
    return EXIT_SUCCESS;
}

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the appending was successful; non-zero for failure.
int AppendLinkedList(LinkedListPtr list, int data) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNode *newNode = CreateLinkedListNode(data);
    if (newNode == NULL) {
        return EXIT_FAILURE;
    }
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->num_elements++;
    return EXIT_SUCCESS;
}

// Prints out the given LinkedListPtr.
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the printing was successful; non-zero for failure.
int PrintLinkedList(LinkedListPtr list) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr temp;
    for (temp = list->head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n\n");
    return EXIT_SUCCESS;
}

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode *CreateLinkedListNode(int data) {
    LinkedListNode *newNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node) {
    if (node == NULL) {
        return EXIT_FAILURE;
    }
    free(node);
    return EXIT_SUCCESS;
}

// Removes a given element from a linkedList.
//
// INPUT: A pointer to a linked list.
// INPUT: A ListNodePtr that points to a LLNode to be removed from the list.
//
// Returns 0 if the destroy was successful
// (primarily that the provide Ptr is in the list and could be free'd).
int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr) {
    if (list == NULL || list->head == NULL || ptr == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr temp = list->head;
    LinkedListNodePtr prev = NULL;
    while (temp != ptr) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != ptr) {
        return EXIT_FAILURE;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
    list->num_elements--;
    return EXIT_SUCCESS;
}
