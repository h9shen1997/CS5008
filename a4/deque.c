#include "deque.h"

// Creates a deque.
// The customer is responsible for calling DestroyDeque() to destroy the deque
// when done.
//
// Returns a deque; NULL if there is an error;
Deque *CreateDeque() {
    DequePtr deque = (DequePtr)malloc(sizeof(deque));
    if (deque == NULL) {
        return NULL;
    }
    deque->list = CreateLinkedList();
    return deque;
}

// Destroys a deque.
// All structs associated with a deque will be released and freed.
//
// INPUT: A pointer to a deque.
int DestroyDeque(DequePtr deque) {
    if (deque != NULL) {
        DestroyLinkedList(deque->list);
    }
    free(deque);
    return EXIT_SUCCESS;
}

// Adds an element to the left of the deque.
//
// INPUT: A pointer to a deque.
// INPUT: The value to be added into the deque.
//
// Returns 0 if pushing to the left was successful; non-zero for failure.
int PushLeft(DequePtr deque, int data) {
    if (deque == NULL) {
        return EXIT_FAILURE;
    }
    AddLeft(deque->list, data);
    return EXIT_SUCCESS;
}

// Adds an element to the right of the deque.
//
// INPUT: A pointer to a deque.
// INPUT: The value to be added into the deque.
//
// Returns 0 if pushing to the right was successful; non-zero for failure.
int PushRight(DequePtr deque, int data) {
    if (deque == NULL) {
        return EXIT_FAILURE;
    }
    AddRight(deque->list, data);
    return EXIT_SUCCESS;
}

// Shows but does not delete the leftmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns the linkedlist node indicating the leftmost element of the deque.
LinkedListNodePtr PeekLeft(DequePtr deque) {
    if (deque == NULL || deque->list == NULL) {
        return NULL;
    }
    return deque->list->head;
}

// Delete the leftmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns 0 if popping from the left was successful; non-zero for failure.
int PopLeft(DequePtr deque) {
    if (deque == NULL || deque->list == NULL) {
        return EXIT_FAILURE;
    }
    return RemoveLeft(deque->list);
}

// Shows but does not delete the rightmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns the linkedlist node indicating the rightmost element of the deque.
LinkedListNodePtr PeekRight(DequePtr deque) {
    if (deque == NULL || deque->list == NULL) {
        return NULL;
    }
    return deque->list->tail;
}

// Delete the rightmost element of the deque.
//
// INPUT: A pointer to a deque.
//
// Returns 0 if popping from the right was successful; non-zero for failure.
int PopRight(DequePtr deque) {
    if (deque == NULL || deque->list == NULL) {
        return EXIT_FAILURE;
    }
    return RemoveRight(deque->list);
}

// Prints all the value in the deque starting from the leftmost element.
//
// INPUT: A pointer to a deque.
void PrintDeque(DequePtr deque) { PrintLinkedList(deque->list); }
