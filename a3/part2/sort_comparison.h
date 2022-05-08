#ifndef SORT_COMPARISON_H
#define SORT_COMPARISON_H

#include <stdio.h>
#include <stdlib.h>

// Heap Sort methods.
void Heapify(int *arr, int size, int i);
void MakeHeap(int *arr, int size);
void HeapSort(int *arr, int size);

// Counting Sort method.
void CountingSort(int *arr, int size, int range);

// Quicksort with shuffle and the fisrt element as pivot methods.
void Shuffle(int *arr, int n);
int PartitionShuffle(int *arr, int begin, int end);
void Quicksort(int *arr, int begin, int end);
void QuicksortShuffle(int *arr, int begin, int end);

// Quicksort with median as pivot methods.
int FindMedian(int *arr, int begin, int end);
int PartitionMedian(int *arr, int begin, int end);
void QuicksortMedian(int *arr, int begin, int end);
int Max(int a, int b);
int Min(int a, int b);

// Swap method.
void Swap(int *a, int *b);

#endif