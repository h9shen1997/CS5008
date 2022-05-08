#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort_comparison.h"

// Counting sort algorithm
//
// INPUT: an integer arr
// INPUT: the size of the array
// INPUT: the range of the values in the array, from 0 to N.
void CountingSort(int *arr, int size, int range) {
    int output[size];
    int count[range];
    memset(count, 0, sizeof(count));
    int i;
    for (i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}
