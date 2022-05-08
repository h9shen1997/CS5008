#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void heapify(int* arr, int size, int index) {
    int high = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[high]) high = left;

    if (right < size && arr[right] > arr[high]) high = right;
    if (high != index) {
        int temp = arr[index];
        arr[index] = arr[high];
        arr[high] = temp;
        heapify(arr, size, high);
    }
}

void buildHeap(int* arr, int n) {
    int start = (n / 2) - 1;
    int i;
    for (i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

bool isValidMaxHeap(int* arr, int size) {
    if (size == 0 || size == 1) return true;
    int i;
    for (i = 1; i < size; i++) {
        int p = (i - 1) / 2;
        if (arr[i] >= arr[p]) return false;
    }
    return true;
}

void print(int* arr, int size) {
    int i;
    printf("[");
    for (i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    printf("]\n");
}

void peek(int* heap) { printf("PEEK: %d\n", heap[0]); }

int main() {
    int arr[5] = {11, 3, 5, 2, 5};
    printf("is valid max heap: %d\n", isValidMaxHeap(arr, 5));
    int* p = arr;
    buildHeap(arr, 5);
    printf("is valid max heap: %d\n", isValidMaxHeap(arr, 5));
    return 0;
}
