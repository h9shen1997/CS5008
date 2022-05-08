#ifndef LINKEDLIST_PRIV_H
#define LINKEDLIST_PRIV_H
#include <assert.h>
#include <stdint.h>

// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
    void* payload;         // Pointer to a string, most likely on the heap
    struct ll_node* next;  // next node in list, or NULL
    struct ll_node* prev;  // prev node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
struct ll_head {
    uint64_t numElements;    //  # elements in the list
    LinkedListNodePtr head;  // head of linked list, or NULL if empty
    LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
};

LinkedListNodePtr CreateLinkedListNode(void* data);

void DestroyLinkedListNode(LinkedListNodePtr node);

int CompareString(const void* payloadA, const void* payloadB);

void FreeString(void* payload);

#endif  // LINKEDLIST_PRIV_H