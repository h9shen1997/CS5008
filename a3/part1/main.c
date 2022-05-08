#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include "linkedlist.h"
#define LENGTH 50
#define MIN_VAL 1
#define MAX_VAL 101
#define SEP_NUM 80

// Print a separation line using the symbol '='
void PrintSeparation() {
    int i;
    for(i = 0; i < SEP_NUM; i++) {
        printf("=");
    }
    printf("\n");
}

// Print unsorted and sorted version of linked list with 50 random values ranging
// from 1 to 100, inclusive, into the console.
int main()
{
    srand(time(0));
    LinkedListPtr list = CreateLinkedList();
    PrintSeparation();
    printf("Adding 50 random values ranging from 1 to 100, inclusive, to the linked list...\n\n");

    int i;
    for (i = 0; i < LENGTH; i++)
    {
        int data = MIN_VAL + (rand() % (MAX_VAL - MIN_VAL));
        AppendLinkedList(list, data);
    }

    printf("Unsorted linked list:\n");
    PrintLinkedList(list);

    printf("Calling sort function...\n\n");
    Sort(list);

    printf("Sorted linked list:\n");
    PrintLinkedList(list);

    DestroyLinkedList(list);

    printf("\nProgram completed successfully!\n");
    PrintSeparation();
    return EXIT_SUCCESS;
}
