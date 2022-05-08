#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_comparison.h"

// Shuffle the array randomly.
//
// INPUT: an integer array
// INPUT: the size of the array
void Shuffle(int *arr, int n) {
    srand(time(0));
    if (n > 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            Swap(&arr[i], &arr[j]);
        }
    }
}

// Partition the integer array for the given range
//
// INPUT: an integer array
// INPUT: the beginning of the array
// INPUT: the ending of the array
//
// Returns the index of the pivot.
int PartitionShuffle(int *arr, int begin, int end) {
    Swap(&arr[begin], &arr[end]);
    int pivot = arr[end];
    int i = begin - 1;
    int cur;
    for (cur = begin; cur <= end; cur++) {
        if (arr[cur] <= pivot) {
            i++;
            Swap(&arr[cur], &arr[i]);
        }
    }
    return i;
}

// Quicksort algorithm helper.
//
// INPUT: an integer array
// INPUT: the begining of the array
// INPUT: the ending of the array
void Quicksort(int *arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = PartitionShuffle(arr, begin, end);
    Quicksort(arr, begin, pivot - 1);
    Quicksort(arr, pivot + 1, end);
}

// Quicksort algorithm with shuffle. Then use the begin index as the pivot.
//
// INPUT: an integer array
// INPUT: the begining of the array
// INPUT: the ending of the array
void QuicksortShuffle(int *arr, int begin, int end) {
    Shuffle(arr, end - begin + 1);
    Quicksort(arr, begin, end);
}

