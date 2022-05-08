#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int SIZE = 26;
const char LETTERS[] = "abcdefghijklmnopqrstuvwxyz";
const char LETTERS_UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef char Character;
typedef int Integer;

typedef struct Pair {
    char* key;
    int* value;
} Pair;

typedef struct Node {
    Pair* pair;
    struct Node* next;
} Node;

typedef struct Map {
    Node** data;
    int size;
} Map;

int hash(const char* key) {
    char c = key[0];
    return 0;
}

Map* createMap(char* key, int* value, int size) {
    Node* n = (Node*)malloc(sizeof(Node));
    Pair* p = (Pair*)malloc(sizeof(Pair));
    p->key = key;
    p->value = value;
    n->pair = p;
    n->next = NULL;
    Map* m = (Map*)malloc(sizeof(Map));
    Node** d = (Node**)malloc(sizeof(Node*) * size);
    int index = hash(key);
    d[index] = n;

    m->data = d;
    m->size = 1;
    return m;
}

int getIndex(char c) {
    int i = 0;
    while (i < 26 && c != LETTERS[i] || c != LETTERS_UPPER[i]) {
        i++;
    }
    return i;
}

Node* get(Map* map, const char* key) {
    int index = hash(key);

    Node* temp = (Node*)malloc(sizeof(Node));
    temp = map->data[index];
    while (temp != NULL) {
        Pair* pair = temp->pair;
        const char* k = pair->key;
        if (strcmp(key, k) == 0) {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

/**
 * @brief put a key value pair into the hashmap
 *
 * First, calculate the hash from the given key and check if the bucket at that
 * already contains a node. If the bucket is currently empty, simply make the
 * new node first element of the bucket. If there are already elements in the
 * bucket, then append the new node to the last node within that bucket.
 *
 * @param map the hashmap
 * @param key the key of the key-value pair
 * @param value the value of the key-value pair
 */
void put(Map* map, char* key, int* value) {
    int index = hash(key);
    Node** data = map->data;
    Node* temp = data[index];
    Node* prev;
    Pair* newPair = (Pair*)malloc(sizeof(Pair));
    newPair->key = key;
    newPair->value = value;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->pair = newPair;
    // If there is no element in this bucket yet, simply make the new node first
    // element of the bucket and return.
    if (temp == NULL) {
        data[index] = newNode;
        return;
    }
    // Otherwise, iterate until the last element, and append the new node to the
    // next element of the last element.
    while (temp != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newNode;
}

int isEmpty(Map* map) { return map->size == 0; }

int main() {
    srand(time(NULL));

    char* k1 = (char*)malloc(sizeof(Character));
    k1 = "alpha";

    int* v1 = (int*)malloc(sizeof(Integer));
    *v1 = 10;

    char* k2 = (char*)malloc(sizeof(Character));
    k2 = "beta";

    int* v2 = (int*)malloc(sizeof(Integer));
    *v2 = 20;

    Map* m = createMap(k1, v1, SIZE);
    printf("%d\n", *(m->data[0]->pair->value));

    put(m, k2, v2);

    Node** data = m->data;
    Node* n1 = data[0];
    Pair* p1 = n1->pair;
    printf("the value is %d\n", *p1->value);

    Node* n2 = n1->next;
    Pair* p2 = n2->pair;
    printf("the value is %d\n", *p2->value);

    Node* gNode = get(m, k1);
    Pair* gPair = gNode->pair;

    printf("testing get %d\n", *(gPair->value));
    return 0;
}
