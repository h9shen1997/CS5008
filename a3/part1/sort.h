#include "linkedlist.h"

#ifndef SORT_H
#define SORT_H

// Sort the linked list in asending order.
//
// INPUT: a pointer to the linked list.
void Sort(LinkedListPtr);

// Sort thelinked list using insertion sort.
//
// INPUT: a pointer to the pointer of the linked list head node.
void InsertionSort(LinkedListNodePtr *);

// Sorting helper function to insert the node into the correct position in the
// linked list.
//
// INPUT: a pointer to the pointer of the linked list head node.
// INPUT: a pointer to the node to be inserted into the correct position.
void SortedInsert(LinkedListNodePtr *, LinkedListNodePtr);
#endif
