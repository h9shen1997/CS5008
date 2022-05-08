#include <stdio.h>

#include "sort_comparison.h"

// Heapify the integer array and make it a heap.
//
// INPUT: an integer array
// INPUT: the size of the integer array
// INPUT: the largest element of the current process
void Heapify(int *arr, int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        Swap(&arr[i], &arr[largest]);
        Heapify(arr, size, largest);
    }
}

// Make a heap from the integer array.
//
// INPUT: an integer array
// INPUT: the size of the integer array
void MakeHeap(int *arr, int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        Heapify(arr, size, i);
    }
}

// Heapsort algorithm.
//
// INPUT: an integer array
// INPUT: the size of the integer array
void HeapSort(int *arr, int size) {
    MakeHeap(arr, size);
    int i;
    for (i = size - 1; i >= 0; i--) {
        Swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}