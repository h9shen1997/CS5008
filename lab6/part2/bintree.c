#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int* value;
    struct Tree* left;
    struct Tree* right;
    int size;
} Tree;

void printAllValues(Tree* t) {
    if (t == NULL) return;

    printf("Value is %d.\n", *(t->value));
    printAllValues(t->left);
    printAllValues(t->right);
}

Tree* construct(int i) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    int* v = (int*)malloc(sizeof(int));
    *v = i;
    t->value = v;
    t->left = NULL;
    t->right = NULL;
    t->size = 0;
    return t;
}

int preOrder(Tree* t, int i) {
    if (t == NULL) return 0;

    int ret = *(t->value) == i;
    int left = preOrder(t->left, i);
    int right = preOrder(t->right, i);

    return ret || left || right;
}

void add(Tree* t, int i) {
    if (t->left == NULL && t->right == NULL) {
        Tree* nt = construct(i);
        if (i <= *(t->value)) {
            t->left = nt;
        } else {
            t->right = nt;
        }
        return;
    }

    t->size++;

    if (i <= *(t->value)) {
        if (t->left == NULL) {
            Tree* nt = construct(i);
            t->left = nt;
            return;
        } else {
            add(t->left, i);
        }
    } else {
        if (t->right == NULL) {
            Tree* nt = construct(i);
            t->right = nt;
            return;
        } else {
            add(t->right, i);
        }
    }
}

// Helper function to maintain a min/max range to validate BST.
int isBSTHelper(Tree* t, int* min, int* max) {
    if (t == NULL) return 1;
    if ((min != NULL && *(t->value) <= *min) ||
        (max != NULL && *(t->value) >= *max))
        return 0;
    return isBSTHelper(t->left, min, t->value) &&
           isBSTHelper(t->right, t->value, max);
}

// Validate whether the tree is a BST.
int isBST(Tree* t) { return isBSTHelper(t, NULL, NULL); }

// Print the message based on whether the tree is BST.
void printIsBST(Tree* t) {
    if (isBST(t)) {
        printf("The tree is a BST.\n");
    } else {
        printf("The tree is not a BST.\n");
    }
}

// Return the number of nodes in the tree using recursion.
int size(Tree* t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + size(t->left) + size(t->right);
}

// Free the tree in the post order traversal.
void freeTree(Tree* t) {
    if (t->left != NULL) {
        freeTree(t->left);
    }
    if (t->right != NULL) {
        freeTree(t->right);
    }
    if (t != NULL) {
        free(t->value);
        free(t);
    }
}

int main() {
    printf("Values added into the tree are 1, 2, 3, 4, 5.\n");
    Tree* t1 = construct(1);
    add(t1, 2);
    add(t1, 3);
    add(t1, 4);
    add(t1, 5);

    printAllValues(t1);

    // The tree is currently a BST.
    printIsBST(t1);

    // Print the size of the tree, aka, the number of nodes in the tree.
    printf("The size of the tree is %d.\n", size(t1));

    // Add an extra node in the tree to make it not a BST and validate.
    printf(
        "Add another 2 into the tree to make it an invalid BST and "
        "validate...\n");
    add(t1, 4);
    printIsBST(t1);

    // Free all the tree nodes to make sure no memory leak.
    freeTree(t1);
    return EXIT_SUCCESS;
}
