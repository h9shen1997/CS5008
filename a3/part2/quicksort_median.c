#include <stdio.h>

#include "sort_comparison.h"

// Find the max of the two integer value.
//
// INPUT: first integer
// INPUT: second integer
//
// Returns the max of the two values.
int Max(int a, int b) { return a > b ? a : b; }

// Find the min of the two integer value.
//
// INPUT: first integer
// INPUT: second integer
//
// Returns the min of the two values.
int Min(int a, int b) { return a > b ? b : a; }

// Find the median of the current processing range from the first, middle, and
// last element of the current processing range.
//
// INPUT: an integer array
// INPUT: begin index of the current processing range
// INPUT: end index of the current processing range
//
// Returns the median value as the pivot.
int FindMedian(int *arr, int begin, int end) {
    int mid = begin + (end - begin) / 2;
    int a = arr[begin];
    int b = arr[mid];
    int c = arr[end];
    int median = Max(Min(a, b), Min(Max(a, b), c));
    if (median == a) {
        return begin;
    }
    if (median == b) {
        return mid;
    }
    return end;
}

// Partition the integer array for the given range
//
// INPUT: an integer array
// INPUT: the beginning of the array
// INPUT: the ending of the array
//
// Returns the index of the pivot.
int PartitionMedian(int *arr, int begin, int end) {
    int pivot_index = FindMedian(arr, begin, end);
    Swap(&arr[pivot_index], &arr[end]);
    int i = begin - 1;
    int cur;
    for (cur = begin; cur <= end; cur++) {
        if (arr[cur] <= arr[end]) {
            i++;
            Swap(&arr[cur], &arr[i]);
        }
    }
    return i;
}

// Quicksort algorithm.
//
// INPUT: an integer array
// INPUT: the begining of the array
// INPUT: the ending of the array
void QuicksortMedian(int *arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = PartitionMedian(arr, begin, end);
    QuicksortMedian(arr, begin, pivot - 1);
    QuicksortMedian(arr, pivot + 1, end);
}