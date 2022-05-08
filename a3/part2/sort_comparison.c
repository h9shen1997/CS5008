#include "sort_comparison.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH_16 16
#define LENGTH_64 64
#define LENGTH_128 128
#define LENGTH_512 512
#define LENGTH_1024 1024
#define LENGTH_2048 2048
#define RESULT_LENGTH 6
#define MIN_VALUE 1
#define MAX_VALUE 20000
#define SEP_NUM 80

// Print a separation line using the symbol '='
void PrintSeparation() {
    int i;
    for (i = 0; i < SEP_NUM; i++) {
        printf("=");
    }
    printf("\n");
}

// Print the header of the output table with formatting.
void PrintHeader() {
    printf("%20s", "Array Size");
    printf("%10d", LENGTH_16);
    printf("%10d", LENGTH_64);
    printf("%10d", LENGTH_128);
    printf("%10d", LENGTH_512);
    printf("%10d", LENGTH_1024);
    printf("%10d", LENGTH_2048);
    printf("\n");
}

// Print the result based on the sort result array and its algorithm name with
// formatting.
void PrintResult(clock_t *arr, char *algoName) {
    int i;
    printf("%20s", algoName);
    for (i = 0; i < RESULT_LENGTH; i++) {
        printf("%10.1Lf", (long double)arr[i]);
    }
    printf("\n");
}

// Main function to run the sorting comparison.
int main() {
    PrintSeparation();
    printf(
        "The time taken for each sorting algorithms in (ms) for different "
        "array sizes...\n\n");
    clock_t start, stop;
    srand(time(0));

    int i;
    int arrLenOf16[LENGTH_16];
    int arrLenOf64[LENGTH_64];
    int arrLenOf128[LENGTH_128];
    int arrLenOf512[LENGTH_512];
    int arrLenOf1024[LENGTH_1024];
    int arrLenOf2048[LENGTH_2048];

    clock_t quicksortShuffleResult[RESULT_LENGTH];
    clock_t quicksortMedianResult[RESULT_LENGTH];
    clock_t coutingsortResult[RESULT_LENGTH];
    clock_t heapsortResult[RESULT_LENGTH];

    for (i = 0; i < LENGTH_16; i++) {
        arrLenOf16[i] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    }

    // Always copy the original random array to make sure all four algorithms
    // are sorting the same array to ensure consistency.
    int arrLenOf16Copy[LENGTH_16];
    memcpy(arrLenOf16Copy, arrLenOf16, sizeof(arrLenOf16Copy));
    start = clock();
    Quicksort(arrLenOf16Copy, 0, LENGTH_16 - 1);
    stop = clock();
    quicksortShuffleResult[0] = stop - start;

    memcpy(arrLenOf16Copy, arrLenOf16, sizeof(arrLenOf16Copy));
    start = clock();
    QuicksortMedian(arrLenOf16Copy, 0, LENGTH_16 - 1);
    stop = clock();
    quicksortMedianResult[0] = stop - start;

    memcpy(arrLenOf16Copy, arrLenOf16, sizeof(arrLenOf16Copy));
    start = clock();
    CountingSort(arrLenOf16Copy, LENGTH_16, MAX_VALUE);
    stop = clock();
    coutingsortResult[0] = stop - start;

    memcpy(arrLenOf16Copy, arrLenOf16, sizeof(arrLenOf16Copy));
    start = clock();
    HeapSort(arrLenOf16Copy, LENGTH_16);
    stop = clock();
    heapsortResult[0] = stop - start;

    for (i = 0; i < LENGTH_64; i++) {
        arrLenOf64[i] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    }

    int arrLenOf64Copy[LENGTH_64];
    memcpy(arrLenOf64Copy, arrLenOf64, sizeof(arrLenOf64Copy));
    start = clock();
    Quicksort(arrLenOf64Copy, 0, LENGTH_64 - 1);
    stop = clock();
    quicksortShuffleResult[1] = stop - start;

    memcpy(arrLenOf64Copy, arrLenOf64, sizeof(arrLenOf64Copy));
    start = clock();
    QuicksortMedian(arrLenOf64Copy, 0, LENGTH_64 - 1);
    stop = clock();
    quicksortMedianResult[1] = stop - start;

    memcpy(arrLenOf64Copy, arrLenOf64, sizeof(arrLenOf64Copy));
    start = clock();
    CountingSort(arrLenOf64Copy, LENGTH_64, MAX_VALUE);
    stop = clock();
    coutingsortResult[1] = stop - start;

    memcpy(arrLenOf64Copy, arrLenOf64, sizeof(arrLenOf64Copy));
    start = clock();
    HeapSort(arrLenOf64Copy, LENGTH_64);
    stop = clock();
    heapsortResult[1] = stop - start;

    for (i = 0; i < LENGTH_128; i++) {
        arrLenOf128[i] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    }

    int arrLenOf128Copy[LENGTH_128];
    memcpy(arrLenOf128Copy, arrLenOf128, sizeof(arrLenOf128Copy));
    start = clock();
    Quicksort(arrLenOf128Copy, 0, LENGTH_128 - 1);
    stop = clock();
    quicksortShuffleResult[2] = stop - start;

    memcpy(arrLenOf128Copy, arrLenOf128, sizeof(arrLenOf128Copy));
    start = clock();
    QuicksortMedian(arrLenOf128Copy, 0, LENGTH_128 - 1);
    stop = clock();
    quicksortMedianResult[2] = stop - start;

    memcpy(arrLenOf128Copy, arrLenOf128, sizeof(arrLenOf128Copy));
    start = clock();
    CountingSort(arrLenOf128Copy, LENGTH_128, MAX_VALUE);
    stop = clock();
    coutingsortResult[2] = stop - start;

    memcpy(arrLenOf128Copy, arrLenOf128, sizeof(arrLenOf128Copy));
    start = clock();
    HeapSort(arrLenOf128Copy, LENGTH_128);
    stop = clock();
    heapsortResult[2] = stop - start;

    for (i = 0; i < LENGTH_512; i++) {
        arrLenOf512[i] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    }

    int arrLenOf512Copy[LENGTH_512];
    memcpy(arrLenOf512Copy, arrLenOf512, sizeof(arrLenOf512Copy));
    start = clock();
    Quicksort(arrLenOf512Copy, 0, LENGTH_512 - 1);
    stop = clock();
    quicksortShuffleResult[3] = stop - start;

    memcpy(arrLenOf512Copy, arrLenOf512, sizeof(arrLenOf512Copy));
    start = clock();
    QuicksortMedian(arrLenOf512Copy, 0, LENGTH_512 - 1);
    stop = clock();
    quicksortMedianResult[3] = stop - start;

    memcpy(arrLenOf512Copy, arrLenOf512, sizeof(arrLenOf512Copy));
    start = clock();
    CountingSort(arrLenOf512Copy, LENGTH_512, MAX_VALUE);
    stop = clock();
    coutingsortResult[3] = stop - start;

    memcpy(arrLenOf512Copy, arrLenOf512, sizeof(arrLenOf512Copy));
    start = clock();
    HeapSort(arrLenOf512Copy, LENGTH_512);
    stop = clock();
    heapsortResult[3] = stop - start;

    for (i = 0; i < LENGTH_1024; i++) {
        arrLenOf1024[i] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    }

    int arrLenOf1024Copy[LENGTH_1024];
    memcpy(arrLenOf1024Copy, arrLenOf1024, sizeof(arrLenOf1024Copy));
    start = clock();
    Quicksort(arrLenOf1024Copy, 0, LENGTH_1024 - 1);
    stop = clock();
    quicksortShuffleResult[4] = stop - start;

    memcpy(arrLenOf1024Copy, arrLenOf1024, sizeof(arrLenOf1024Copy));
    start = clock();
    QuicksortMedian(arrLenOf1024Copy, 0, LENGTH_1024 - 1);
    stop = clock();
    quicksortMedianResult[4] = stop - start;

    memcpy(arrLenOf1024Copy, arrLenOf1024, sizeof(arrLenOf1024Copy));
    start = clock();
    CountingSort(arrLenOf1024Copy, LENGTH_1024, MAX_VALUE);
    stop = clock();
    coutingsortResult[4] = stop - start;

    memcpy(arrLenOf1024Copy, arrLenOf1024, sizeof(arrLenOf1024Copy));
    start = clock();
    HeapSort(arrLenOf1024Copy, LENGTH_1024);
    stop = clock();
    heapsortResult[4] = stop - start;

    for (i = 0; i < LENGTH_2048; i++) {
        arrLenOf2048[i] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE));
    }

    int arrLenOf2048Copy[LENGTH_2048];
    memcpy(arrLenOf2048Copy, arrLenOf2048, sizeof(arrLenOf2048Copy));
    start = clock();
    Quicksort(arrLenOf2048Copy, 0, LENGTH_2048 - 1);
    stop = clock();
    quicksortShuffleResult[5] = stop - start;

    memcpy(arrLenOf2048Copy, arrLenOf2048, sizeof(arrLenOf2048Copy));
    start = clock();
    QuicksortMedian(arrLenOf2048Copy, 0, LENGTH_2048 - 1);
    stop = clock();
    quicksortMedianResult[5] = stop - start;

    memcpy(arrLenOf2048Copy, arrLenOf2048, sizeof(arrLenOf2048Copy));
    start = clock();
    CountingSort(arrLenOf2048Copy, LENGTH_2048, MAX_VALUE);
    stop = clock();
    coutingsortResult[5] = stop - start;

    memcpy(arrLenOf2048Copy, arrLenOf2048, sizeof(arrLenOf2048Copy));
    start = clock();
    HeapSort(arrLenOf2048Copy, LENGTH_2048);
    stop = clock();
    heapsortResult[5] = stop - start;

    char *algoAName = "Quicksort Shuffle";
    char *algoBName = "Quicksort Median";
    char *algoCName = "Countingsort";
    char *algoDName = "Heapsort";

    PrintHeader();
    PrintResult(quicksortShuffleResult, algoAName);
    PrintResult(quicksortMedianResult, algoBName);
    PrintResult(coutingsortResult, algoCName);
    PrintResult(heapsortResult, algoDName);

    printf("\nProgram completed successfully!\n");
    PrintSeparation();
    return EXIT_SUCCESS;
}