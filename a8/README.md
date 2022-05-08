# Assignment 8: Multi-threaded Searching

## Name:
Haotian Shen

## Observations:
The program is faster when using more threads, especially when the input file is relatively large.

## Files included:
- ```Makefile```
- ```mt_search.h```
- ```mt_search.c```
- ```README.md```
- ```inputs/input1.txt```
- ```inputs/input2.txt```
- ```inputs/nums10000.txt```

## How to run the program:
* Run the program with multiple pre-defined commands in the Makefile:
```make run```
* Run the program with Valgrind check:
```make valgrind```
* Run the program with clint.py:
```make style``` *Important: make sure you have clint.py in your $PATH or bin folder*
No errors were detected from my submission. 

## Sample output:
* Using ```make run```
```
bash-4.2$ make run
====================================
Cleaning the directory
====================================
rm -f mt_search
====================================
Compiling mt_search...
====================================
gcc -pthread -o mt_search mt_search.c 
====================================
Running mt_search with multiple sets of cmd arguments
====================================
./mt_search inputs/input1.txt 5 2 11
Searching 5 in file: inputs/input1.txt.
The target 5 was found 1 times.
The target 5 was found on line 6.
====================================
./mt_search inputs/input1.txt 2 3 11
Searching 2 in file: inputs/input1.txt.
The target 2 was found 1 times.
The target 2 was found on line 3.
====================================
./mt_search inputs/input2.txt 3 4 26
Searching 3 in file: inputs/input2.txt.
The target 3 was found 5 times.
The target 3 was found on line 11.
The target 3 was found on line 12.
The target 3 was found on line 13.
The target 3 was found on line 14.
The target 3 was found on line 15.
====================================
./mt_search inputs/nums10000.txt 527 20 1000
Searching 527 in file: inputs/nums10000.txt.
The target 527 was found 1 times.
The target 527 was found on line 415.
```
* Using ```make valgrind```
```
bash-4.2$ make valgrind
====================================
Cleaning the directory
====================================
rm -f mt_search
====================================
Compiling mt_search...
====================================
gcc -pthread -o mt_search mt_search.c 
====================================
Running valgrind on mt_search to check for memory usage
====================================
valgrind --leak-check=full ./mt_search inputs/input2.txt 3 4 26
==116751== Memcheck, a memory error detector
==116751== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==116751== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==116751== Command: ./mt_search inputs/input2.txt 3 4 26
==116751== 
Searching 3 in file: inputs/input2.txt.
The target 3 was found 5 times.
The target 3 was found on line 11.
The target 3 was found on line 12.
The target 3 was found on line 13.
The target 3 was found on line 14.
The target 3 was found on line 15.
==116751== 
==116751== HEAP SUMMARY:
==116751==     in use at exit: 0 bytes in 0 blocks
==116751==   total heap usage: 34 allocs, 34 frees, 6,210 bytes allocated
==116751== 
==116751== All heap blocks were freed -- no leaks are possible
==116751== 
==116751== For lists of detected and suppressed errors, rerun with: -s
==116751== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
*No memory leak is possible!*

## Hours taken
2 hours

## Collaborator:
None

## External resources:
None


