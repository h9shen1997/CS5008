#include <stdio.h>
#include <stdlib.h>

#include "doubly.h"

#ifndef DEQUE_H
#define DEQUE_H

// This struct represents a deque, which can add and delete elements from both
// sides.
typedef struct deque {
    LinkedListPtr list;
} Deque, *DequePtr;

// Creates a deque.
// The customer is responsible for calling DestroyDeque() to destroy the deque
// when done.
//
// Returns a deque; NULL if there is an error;
Deque *CreateDeque();

// Destroys a deque.
// All structs associated with a deque will be released and freed.
//
// INPUT: A pointer to a deque.
int DestroyDeque(DequePtr);

// Adds an element to the left of the deque.
//
// INPUT: A pointer to a deque.
// INPUT: The value to be added into the deque.
//
// Returns 0 if pushing to the left was successful; non-zero for failure.
int PushLeft(DequePtr, int);

// Adds an element to the right of the deque.
//
// INPUT: A pointer to a deque.
// INPUT: The value to be added into the deque.
//
// Returns 0 if pushing to the right was successful; non-zero for failure.
int PushRight(DequePtr, int);

// Shows but does not delete the leftmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns the linkedlist node indicating the leftmost element of the deque.
LinkedListNodePtr PeekLeft(DequePtr);

// Delete the leftmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns 0 if popping from the left was successful; non-zero for failure.
int PopLeft(DequePtr);

// Shows but does not delete the rightmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns the linkedlist node indicating the rightmost element of the deque.
LinkedListNodePtr PeekRight(DequePtr);

// Delete the rightmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns 0 if popping from the right was successful; non-zero for failure.
int PopRight(DequePtr);

// Prints all the value in the deque starting from the leftmost element.
//
// INPUT: A pointer to a deque.
void PrintDeque(DequePtr);

#endif
