/**
 * @file mt_search.h
 * @brief Function prototype for the multithreaded search program
 *
 * This contains the prototype to search a given target from a given file using
 * multithreaded program in a thread safe manner. All the comments are in this
 * header file. No comments for function are present in the c file.
 *
 * @author Haotian Shen (h9shen)
 * @bug No known bugs
 */
#ifndef _MT_SEARCH_H
#define _MT_SEARCH_H

#include <assert.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The maximum result can be displayed.
#define MAX_NUM_RESULTS 100

/**
 * @brief Searches the given file from a specified index for the target.
 *
 * The thread number will be used to calculate the starting index to search. The
 * ending index is the smaller of either total number of lines in the file or
 * starting index plus the section size. The maximum number of results is
 * defined to be 100, so if more than 100 targest were found from the search, it
 * will only save the first 100 occurrences line number in the result array.
 * However, the number of results will still be updated to reflect the actual
 * value. The thread_num is a global variable updated using mutex to ensure that
 * value is accurate at all time. No arg was passed in from the pthread_create
 * function because I realized that the arguemnts passed in is tightly coupled
 * with the thread created, so it will create memory leakage that can't be
 * freed. The pthread library may use that same memory region for future
 * pthread_create calls.
 *
 * @param arg the thread number, used to calculate starting index, 0 based.
 * @return A void pointer used to satisfy thread creation.
 */
void* DoSearch(void* arg);

/**
 * @brief Receives all the command line input and populates the global
 * variables.
 *
 * Reads all the cmd arguments and populate the global variable accordingly.
 * Calculates the section size. If the number of lines can be evenly divided by
 * the number of threads, then the section size is just that. Otherwise, the
 * section size is evenly divided except the last thread, in which the remaining
 * will be processed. i.e., 26 lines using 6 threads, the section size will be
 * 5, with the last thread processing only 1 line.
 *
 * @param args an array of cmd input
 */
void ReceiveInput(char* args[]);

/**
 * @brief Reads the input file containing a number on each line using the given
 * filename.
 *
 * The given file has only one number per line. This file is used to search for
 * the target number. Each number will be added to the global data array for
 * further processing. The ReadFile will sem_post after reading all the line to
 * signal the threads to start processing.
 *
 * @param the filename to be used to open a stream to read from.
 */
void ReadFile(char* filename);

/**
 * @brief Creates all the threads and starts them running and stores all the
 * thread IDs in the global threads array.
 *
 * Each thread starts the DoSearch method to search a portion of the input file.
 * The starting index will be passed as the argument to the thread function when
 * the thread is generated.
 */
void CreateThreads();

/**
 * @brief Joins all the threads created.
 *
 * Reason why pthread_join is called separately from pthread_create is due to
 * the nature of sem_wait. Once the first thread has started, sem_wait will
 * consumer the semaphore and no other threads are able to replenish it, so the
 * threads will be stuck forever. This method will use the global thread IDs to
 * join them without receiving an argument.
 */
void JoinThreads();

/**
 * @brief Calls sem_post to release all the threads to do search and joins them
 * together to wait until all searches have been completed.
 *
 * After calling sem_post for all the threads, they will start process and can
 * be joined to make sure to output after all searches are completed.
 */
void ReleaseSemaphoreAndJoin();

/**
 * @brief Prints the result of the multithreaded search.
 *
 * Since the maximum number of results is predefined to be 100. If the number of
 * results exceeds 100, only the first 100 results will be printed. The order of
 * the result is not guaranteed since we are using multithreaded and context
 * switching is determined by CPU. It will first print out a message stating the
 * total results found and will then print out the line number at which the
 * target number is found.
 *
 * @param filename the file to search.
 */
void PrintResults(char* filename);

/**
 * @brief Frees all the malloc spaces and the mutex and semaphore created.
 */
void FreeAll();

#endif
