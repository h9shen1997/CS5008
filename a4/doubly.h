#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// STRUCT DEFINITIONS

// We have 2 structs: One is a LinkedListNode, and one is a LinkedListHead,
// which we create an alias for the pointer.

// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
    int data;              // Data this node holds
    struct ll_node *next;  // next node in list, or NULL
    struct ll_node *prev;  // prev node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_head {
    uint64_t num_elements;   //  # elements in the list
    LinkedListNodePtr head;  // head of linked list, or NULL if empty
    LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
} * LinkedListPtr;

// ======================================================
// LinkedList: A Doubly-Linked List
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedListPtr CreateLinkedList();

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedList(LinkedListPtr list);

// Returns the number of elements in the linked list.
//
// INPUT: A LinkedList
//
// Returns the number of elements in the list.
unsigned int NumElementsInLinkedList(LinkedListPtr list);

// Adds an element to the head of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int InsertLinkedList(LinkedListPtr, int);

// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int AppendLinkedList(LinkedListPtr, int);

// Prints out the given LinkedListPtr.
//
// INPUT: A pointer to the LinkedList that will be printed out.
void PrintLinkedList(LinkedListPtr);

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode *CreateLinkedListNode(int data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);

// Removes a given element from a linkedList.
//
// INPUT: A pointer to a linked list.
// INPUT: A ListNodePtr that points to a LLNode to be removed from the list.
//
// Returns 0 if the destroy was successful
// (primarily that the provide Ptr is in the list and could be free'd).
int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr);

// Adds a given value to the start of the linkedlist.
//
// INPUT: A pointer to a linked list.
// INPUT: The value to be added.
//
// Returns 0 if the addition was successful
int AddLeft(LinkedListPtr, int);

// Removes from the start of the linkedlist.
//
// Returns 0 if the deletion was successful.
int RemoveLeft(LinkedListPtr);

// Adds a given value to the end of the linkedlist.
//
// INPUT: A pointer to a linked list.
// INPUT: The value to be added.
//
// Returns 0 if the addition was successful.
int AddRight(LinkedListPtr, int);

// Removes from the end of the linkedlist.
//
// Returns 0 if the deletion was successful.
int RemoveRight(LinkedListPtr);

// Inserts the given value at the given index in the linked list.
//
// INPUT: A pointer to the linked list.
// INPUT: The value to be inserted.
// INPUT: The index to be inserted.
//
// Returns 0 if the insertion was successful, or returns 1 if the insertion was
// unsuccessful, such as index less than 0 or greater than the largest index of
// the linked list.
int InsertAt(LinkedListPtr, int, int);

// Removes the node at the given index in the linked list.
//
// INPUT: A pointer to the linked list.
// INPUT: The index to be removed.
//
// Returns 0 if the removal was successful, or returns 1 if the removal was
// unsuccessful, such as index less than 0 or greater than the largest index of
// the linked list.
int RemoveAt(LinkedListPtr, int);

// Checks whether the linkedlist contains the given value.
//
// INPUT: A pointer to the linked list.
// INPUT: The value to be checked.
//
// Returns 1 if the linked list contains the given value, 0 otherwise.
int HasValue(LinkedListPtr, int);

#endif
