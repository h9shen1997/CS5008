#include <stdio.h>
#include <stdlib.h>

#include "sort_comparison.h"

// Swap two values based on the pointer passed in.
//
// INPUT: pointer to first element in the array
// INPUT: pointer to second element in the array
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}