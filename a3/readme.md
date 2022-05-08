### Name
Haotian Shen

### Resources used
I have searched for the different types of sorting algorithms.

### Time spent
I spent about 3 hours to complete the assignment.

### Challenging part
Implementing sorting algorithm in linked list is more challenging compared to
array because of the pointer manipulation.

### Part 1

### Files contained
- linkedlist.c
- linkedlist.h
- main.c
- sort.c
- sort.h
- Makefile

### How to run part 1
```
cd part1
make
```

### Output of part 1
Run #1
```
================================================================================
Adding 50 random values ranging from 1 to 100, inclusive, to the linked list...

Unsorted linked list:
72 60 32 45 69 90 53 84 42 15 4 76 56 19 44 68 35 25 35 11 27 9 50 92 51 96 20 31 36 53 44 71 14 63 11 60 46 11 75 12 76 54 50 66 30 26 75 68 16 13 

Calling sort function...

Sorted linked list:
4 9 11 11 11 12 13 14 15 16 19 20 25 26 27 30 31 32 35 35 36 42 44 44 45 46 50 50 51 53 53 54 56 60 60 63 66 68 68 69 71 72 75 75 76 76 84 90 92 96 

Program completed successfully!
================================================================================
```

Run #2
```
================================================================================
Adding 50 random values ranging from 1 to 100, inclusive, to the linked list...

Unsorted linked list:
32 39 89 59 64 13 81 14 72 72 51 41 60 10 30 97 67 63 82 27 92 84 97 30 31 19 56 1 88 44 34 86 39 84 33 68 48 1 64 97 65 12 82 10 54 47 44 18 25 46 

Calling sort function...

Sorted linked list:
1 1 10 10 12 13 14 18 19 25 27 30 30 31 32 33 34 39 39 41 44 44 46 47 48 51 54 56 59 60 63 64 64 65 67 68 72 72 81 82 82 84 84 86 88 89 92 97 97 97 

Program completed successfully!
================================================================================
```

### Part 2

### Files contained
- countingsort.c
- heapsort.c
- quicksort_median.c
- quicksort_shuffle.c
- sort_comparison.c
- sort_comparison.h
- swap.c
- Makefile

### Algorithms implemented
1. Quicksort with shuffle and selecting the first element as the pivot.
2. Quicksort with median of the first, middle, and last element as the pivot.
3. Counting sort (note: this version of implementation can only be applied to all positive numbers).
4. Heapsort.

### How to run part 2
```
cd part2
make
```

### Output of part 2
Run #1
```
================================================================================
The time taken for each sorting algorithms in (ms) for different array sizes...

          Array Size        16        64       128       512      1024      2048
   Quicksort Shuffle       4.0       6.0      11.0      57.0     121.0     247.0
    Quicksort Median       2.0       6.0      13.0      58.0     129.0     274.0
        Countingsort      86.0      77.0      77.0      82.0      84.0      91.0
            Heapsort       2.0       9.0      17.0      84.0     185.0     404.0

Program completed successfully!
================================================================================
```

Run #2
```
================================================================================
The time taken for each sorting algorithms in (ms) for different array sizes...

          Array Size        16        64       128       512      1024      2048
   Quicksort Shuffle       3.0       5.0      10.0      45.0     105.0     222.0
    Quicksort Median       1.0       5.0      12.0      62.0     113.0     243.0
        Countingsort      81.0      79.0      73.0      72.0      75.0      86.0
            Heapsort       2.0       7.0      25.0      74.0     164.0     358.0

Program completed successfully!
================================================================================
```

### Analysis
Based on the output of part 2, four algorithms can be ranked from slowest to fastest in the following order: <br />**Heapsort** < **Quicksort Median** = **Quicksort Shuffle** < **Countingsort**.<br /> In fact, counting sort is the only sorting algorithm with linear time complexity, whereas the other threes are all O(nlogn). However, counting sort can only be applied to smaller array size and utilize a lot of space when sorting large arrays. Thus, personally I think Quicksort Median and Quicksort Shuffle probably can both yield good perfomance.

