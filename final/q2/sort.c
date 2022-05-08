#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

Node* head = NULL;
Node* sorted = NULL;

List* create(int init) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = init;

    List* l = (List*)malloc(sizeof(List));
    l->head = n;
    l->size = 1;
    return l;
}

List* add(List* list, int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;

    List* l = (List*)malloc(sizeof(List));
    n->next = list->head;

    l->head = n;
    l->size = list->size + 1;
    free(list);

    return l;
}

void sortedInsert(Node* newNode) {
    if (sorted == NULL || sorted->data >= newNode->data) {
        newNode->next = sorted;
        sorted = newNode;
    } else {
        Node* cur = sorted;
        while (cur->next != NULL && cur->next->data < newNode->data) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void sort(List* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        Node* next = cur->next;
        sortedInsert(cur);
        cur = next;
    }
    list->head = sorted;
}

bool isSorted(List* list) {
    if (list == NULL || list->head == NULL) return false;
    if (list->head->next == NULL) return true;
    Node* curr = list->head;
    Node* temp = list->head->next;
    while (temp != NULL) {
        if (temp->data < curr->data) return false;
        curr = temp;
        temp = temp->next;
    }

    return true;
}

int main() {
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));

    n1->data = 1;
    n2->data = 2;
    n3->data = 4;
    n4->data = 10;
    List* l1 = (List*)malloc(sizeof(List));
    l1->head = n2;

    bool r1 = isSorted(l1);
    printf("isSorted1: %d\n", r1);

    n2->next = n1;

    bool r2 = isSorted(l1);
    printf("isSorted2: %d\n", r2);

    n1->next = n4;
    n4->next = n3;
    sort(l1);
    printf("isSorted3: %d\n", isSorted(l1));
}
