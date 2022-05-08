#include "deque.h"
#include "doubly.h"

#define SEP_NUM 60

// Print a separation line using the symbol '='
void PrintSeparation() {
    int i;
    for (i = 0; i < SEP_NUM; i++) {
        printf("=");
    }
    printf("\n");
}

// Test the implementation of doubly linked list and deque.
int main() {
    // Doubly linked list
    PrintSeparation();
    printf("Testing doubly linkedlist implementation...\n");
    LinkedListPtr list = CreateLinkedList();
    printf("Populate with some values first...\n");
    AppendLinkedList(list, 1);
    AppendLinkedList(list, 2);
    AppendLinkedList(list, 5);
    AppendLinkedList(list, 7);
    AppendLinkedList(list, 2);
    AppendLinkedList(list, 3);
    printf("The initial values in the linkedlist are:\n");
    PrintLinkedList(list);
    printf("After adding 1 to the right...\n");
    AddRight(list, 1);
    PrintLinkedList(list);
    printf("After adding 8 to the right...\n");
    AddRight(list, 8);
    PrintLinkedList(list);
    printf("After adding 5 to the left...\n");
    AddLeft(list, 5);
    PrintLinkedList(list);
    printf("After adding 3 to the left...\n");
    AddLeft(list, 3);
    PrintLinkedList(list);
    printf("After removing from the left...\n");
    RemoveLeft(list);
    PrintLinkedList(list);
    printf("After removing from the right...\n");
    RemoveRight(list);
    PrintLinkedList(list);
    printf("After removing from index 1...\n");
    RemoveAt(list, 1);
    PrintLinkedList(list);
    printf("After removing from index 4...\n");
    RemoveAt(list, 4);
    PrintLinkedList(list);
    printf("After inserting 4 at index 3...\n");
    InsertAt(list, 4, 3);
    PrintLinkedList(list);
    printf("After inserting 2 at index 1...\n");
    InsertAt(list, 2, 1);
    PrintLinkedList(list);
    printf("Done testing for doubly linkedlist!\n");
    DestroyLinkedList(list);
    PrintSeparation();

    // Deque
    printf("Testing deque implementation...\n");
    DequePtr deque = CreateDeque();
    printf("Push 3 to the left...\n");
    PushLeft(deque, 3);
    PrintDeque(deque);
    printf("Push 4 to the left...\n");
    PushLeft(deque, 4);
    PrintDeque(deque);
    printf("Push 1 to the left...\n");
    PushLeft(deque, 1);
    PrintDeque(deque);
    printf("Push 2 to the right...\n");
    PushRight(deque, 2);
    PrintDeque(deque);
    printf("Push 8 to the right...\n");
    PushRight(deque, 8);
    PrintDeque(deque);
    LinkedListNodePtr left = PeekLeft(deque);
    printf("Peeking element on the left, which is %d.\n", left->data);
    LinkedListNodePtr right = PeekRight(deque);
    printf("Peeking element on the right, which is %d.\n", right->data);
    printf("Pop from left...\n");
    PopLeft(deque);
    PrintDeque(deque);
    printf("Pop from left...\n");
    PopLeft(deque);
    PrintDeque(deque);
    printf("Pop from right...\n");
    PopRight(deque);
    PrintDeque(deque);
    printf("Done testing for deque!\n");
    DestroyDeque(deque);
    PrintSeparation();
    return EXIT_SUCCESS;
}
