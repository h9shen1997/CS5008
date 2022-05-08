#include "doubly.h"

#define HALF_DIVISOR 2
#define FALSE 0
#define TRUE 1

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
void PrintLinkedList(LinkedListPtr list) {
    LinkedListNodePtr temp;
    for (temp = list->head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n\n");
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

// Adds a given value to the start of the linkedlist.
//
// INPUT: A pointer to a linked list.
// INPUT: The value to be added.
//
// Returns 0 if the addition was successful
int AddLeft(LinkedListPtr list, int data) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr newNode = CreateLinkedListNode(data);
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

// Adds a given value to the end of the linkedlist.
//
// INPUT: A pointer to a linked list.
// INPUT: The value to be added.
//
// Returns 0 if the addition was successful.
int AddRight(LinkedListPtr list, int data) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr newNode = CreateLinkedListNode(data);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->num_elements++;
    return EXIT_SUCCESS;
}

// Removes from the start of the linkedlist.
//
// Returns 0 if the deletion was successful.
int RemoveLeft(LinkedListPtr list) {
    if (list == NULL || list->head == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr nodeToBeDeleted = list->head;
    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
        nodeToBeDeleted->next = NULL;
    }
    DestroyLinkedListNode(nodeToBeDeleted);
    list->num_elements--;
    return EXIT_SUCCESS;
}

// Removes from the end of the linkedlist.
//
// Returns 0 if the deletion was successful.
int RemoveRight(LinkedListPtr list) {
    if (list == NULL || list->head == NULL) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr nodeToBeDeleted = list->tail;
    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        nodeToBeDeleted->prev = NULL;
    }
    DestroyLinkedListNode(nodeToBeDeleted);
    list->num_elements--;
    return EXIT_SUCCESS;
}

// Inserts the given value at the given index in the linked list.
//
// INPUT: A pointer to the linked list.
// INPUT: The value to be inserted.
// INPUT: The index to be inserted.
//
// Returns 0 if the insertion was successful, or returns 1 if the insertion was
// unsuccessful, such as index less than 0 or greater than the largest index of
// the linked list.
int InsertAt(LinkedListPtr list, int data, int index) {
    if (list == NULL || index > list->num_elements || index < 0) {
        return EXIT_FAILURE;
    }
    if (index != 0 && index == list->num_elements) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr newNode = CreateLinkedListNode(data);
    if (list->num_elements == 0) {
        list->head = list->tail = newNode;
    } else {
        LinkedListNodePtr itr = list->head;
        while (index-- > 0) {
            itr = itr->next;
        }
        newNode->next = itr;
        newNode->prev = itr->prev;
        if (itr->prev != NULL) {
            itr->prev->next = newNode;
        } else {
            list->head = newNode;
        }
        itr->prev = newNode;
    }
    list->num_elements++;
    return EXIT_SUCCESS;
}

// Removes the node at the given index in the linked list.
//
// INPUT: A pointer to the linked list.
// INPUT: The index to be removed.
//
// Returns 0 if the removal was successful, or returns 1 if the removal was
// unsuccessful, such as index less than 0 or greater than the largest index of
// the linked list.
int RemoveAt(LinkedListPtr list, int index) {
    if (list == NULL || index >= list->num_elements || index < 0) {
        return EXIT_FAILURE;
    }
    LinkedListNodePtr itr = list->head;
    while (index-- > 0) {
        itr = itr->next;
    }
    if (itr == list->head) {
        list->head = list->head->next;
    }
    if (itr->next != NULL) {
        itr->next->prev = itr->prev;
    }
    if (itr->prev != NULL) {
        itr->prev->next = itr->next;
    }
    DestroyLinkedListNode(itr);
    list->num_elements--;
    return EXIT_SUCCESS;
}

// Checks whether the linkedlist contains the given value.
//
// INPUT: A pointer to the linked list.
// INPUT: The value to be checked.
//
// Returns 1 if the linked list contains the given value, 0 otherwise.
int HasValue(LinkedListPtr list, int data) {
    int half = (list->num_elements + 1) / HALF_DIVISOR;
    if (list == NULL || list->head == NULL) {
        return FALSE;
    }
    LinkedListNodePtr itrHead = list->head;
    LinkedListNodePtr itrTail = list->tail;
    int index = 0;
    while (index++ < half && itrHead != NULL && itrTail != NULL) {
        if (itrHead->data == data || itrTail->data == data) {
            return TRUE;
        }
        itrHead = itrHead->next;
        ;
        itrTail = itrTail->prev;
    }
    return FALSE;
}
