/**
 * @file mt_search.c
 * @brief Implementation to search for a given target in the given file using
 * multithreaded program.
 *
 * All the comments are in the header file mt_search.h
 *
 * @author: Haotian Shen (h9shen)
 * @bug No known bugs
 */
#include "mt_search.h"

// ===================================================
// Global Variables
// ===================================================
// Number of targets found in the file.
int num_results = 0;
// The section size of each disjoint set in the given input file to search for.
int section_size;
// The total number of lines of the given input file.
int num_lines;
// Array of numbers to search from, converted from the given input file.
int* data;
// Number to be found.
int target;
// Number of threads to run.
int num_threads;
// Array of indices of target number.
int results[MAX_NUM_RESULTS];
// Mutex for number increment and add to results array.
pthread_mutex_t number_lock;
// Semaphore to wait until all lines of the file are read.
sem_t file_sem;
// All the threads as an array.
pthread_t* threads;
// Current thread index, protected and updated by mutex to calculate starting
// position, 0 based.
int cur_index = 0;

// Avoids clint.py error.
typedef int Integer;

// ===================================================
// Function Implementations
// ===================================================
void* DoSearch(void* arg) {
    pthread_mutex_lock(&number_lock);
    int thread_num = cur_index;
    cur_index++;
    pthread_mutex_unlock(&number_lock);
    sem_wait(&file_sem);
    int i;
    int start_index = section_size * thread_num;
    for (i = start_index; i < start_index + section_size && i < num_lines;
         i++) {
        if (target == data[i]) {
            pthread_mutex_lock(&number_lock);
            if (num_results < MAX_NUM_RESULTS) {
                // Adds 1 to i to make it 1-based line number.
                results[num_results] = i + 1;
            }
            num_results++;
            pthread_mutex_unlock(&number_lock);
        }
    }
    return NULL;
}

void CreateThreads() {
    int i;
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, DoSearch, NULL);
    }
}

void JoinThreads() {
    int i;
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

void FreeAll() {
    free(data);
    free(threads);
    sem_destroy(&file_sem);
    pthread_mutex_destroy(&number_lock);
}

void ReadFile(char* filename) {
    char* line = NULL;
    size_t length;
    FILE* file_ptr = fopen(filename, "r");
    assert(file_ptr != NULL);
    int i = 0;
    while (getline(&line, &length, file_ptr) != -1) {
        char* number_string = malloc(length + 1);
        snprintf(number_string, length + 1, "%s", line);
        int number = atoi(number_string);
        data[i++] = number;
        free(number_string);
    }
    free(line);
    fclose(file_ptr);
    // Increment the semaphore to number of threads, so that all threads waiting 
    // will start searching processes.
    for(i = 0; i < num_threads; i++) {
        sem_post(&file_sem);
    }
}

void PrintResults(char* filename) {
    int i;
    printf("Searching %d in file: %s.\n", target, filename);
    pthread_mutex_lock(&number_lock);
    printf("The target %d was found %d times.\n", target, num_results);
    if (num_results >= MAX_NUM_RESULTS) {
        printf("Only printing the first 100 results.\n");
    }
    for (i = 0; i < MAX_NUM_RESULTS; i++) {
        if (results[i] == -1) {
            pthread_mutex_unlock(&number_lock);
            return;
        }
        printf("The target %d was found on line %d.\n", target, results[i]);
    }
    pthread_mutex_unlock(&number_lock);
}

void ReceiveInput(char* args[]) {
    target = atoi(args[2]);
    num_threads = atoi(args[3]);
    num_lines = atoi(args[4]);
    data = malloc(num_lines * sizeof(Integer));
    assert(data != NULL);
    threads = malloc(sizeof(pthread_t) * num_threads);
    assert(threads != NULL);
    section_size = num_lines % num_threads ? num_lines / num_threads + 1
                                           : num_lines / num_threads;
}

void InitResultArr() {
    int i;
    for (i = 0; i < MAX_NUM_RESULTS; i++) {
        results[i] = -1;
    }
}

int main(int num_args, char* args[]) {
    // Reads in the arguments. Filename will be used in the output.
    char* filename = args[1];
    ReceiveInput(args);

    // Initializes the semaphore value to 0 so that it will wait until somebody
    // called sem_post.
    sem_init(&file_sem, 0, 0);
    pthread_mutex_init(&number_lock, NULL);

    // Initializes the results array to -1, meaning no line has been found yet.
    InitResultArr();

    // Starts all threads with DoSearch and wait for file input.
    CreateThreads(num_threads);

    // Reads the input file and release the semaphore to the threads.
    ReadFile(filename);

    // Joins all the threads after the semaphores have been consumed.
    JoinThreads();

    // Prints out the results.
    PrintResults(filename);

    // Frees all memory spaces allocated by malloc.
    FreeAll();
    exit(0);
}
