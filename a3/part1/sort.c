#include <stdio.h>
#include "linkedlist.h"
#include "sort.h"

// Sort the linked list in asending order.
//
// INPUT: a pointer to the linked list.
void Sort(LinkedListPtr list)
{
    if (list == NULL)
    {
        return;
    }
    InsertionSort(&(list->head));
}

// Sort thelinked list using insertion sort.
//
// INPUT: a pointer to the pointer of the linked list head node.
void InsertionSort(LinkedListNodePtr *head)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }
    LinkedListNodePtr sorted = NULL;
    LinkedListNodePtr current = *head;
    while (current != NULL)
    {
        LinkedListNodePtr next = current->next;
        current->prev = current->next = NULL;
        SortedInsert(&sorted, current);
        current = next;
    }
    *head = sorted;
}

// Sorting helper function to insert the node into the correct position in the
// linked list.
//
// INPUT: a pointer to the pointer of the linked list head node.
// INPUT: a pointer to the node to be inserted into the correct position.
void SortedInsert(LinkedListNodePtr *head, LinkedListNodePtr newNode)
{
    LinkedListNodePtr current;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else if ((*head)->data >= newNode->data)
    {
        newNode->next = *head;
        newNode->next->prev = newNode;
        *head = newNode;
    }
    else
    {
        current = *head;
        while (current->next != NULL && current->next->data < newNode->data)
        {
            current = current->next;
        }

        newNode->next = current->next;

        if (current->next != NULL)
        {
            newNode->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}
