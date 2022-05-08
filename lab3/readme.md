### Problem in grades.c
The float array storing students' grades were not freed after the program completed. 
This has caused the heap space used by this array not freed. Using Valgrind, 
the message displayed is:
```
==157022== 
==157022== HEAP SUMMARY:
==157022==     in use at exit: 8 bytes in 1 blocks
==157022==   total heap usage: 1 allocs, 0 frees, 8 bytes allocated
==157022== 
==157022== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==157022==    at 0x4C29F73: malloc (vg_replace_malloc.c:309)
==157022==    by 0x400673: main (grades.c:13)
==157022== 
==157022== LEAK SUMMARY:
==157022==    definitely lost: 8 bytes in 1 blocks
==157022==    indirectly lost: 0 bytes in 0 blocks
==157022==      possibly lost: 0 bytes in 0 blocks
==157022==    still reachable: 0 bytes in 0 blocks
==157022==         suppressed: 0 bytes in 0 blocks
==157022== 
==157022== For lists of detected and suppressed errors, rerun with: -s
==157022== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

After adding the following line before the return statement:
```
free(p);
```
The problem is solved, and the valgrind message is now:
```
==159118== 
==159118== HEAP SUMMARY:
==159118==     in use at exit: 0 bytes in 0 blocks
==159118==   total heap usage: 1 allocs, 1 frees, 8 bytes allocated
==159118== 
==159118== All heap blocks were freed -- no leaks are possible
==159118== 
==159118== For lists of detected and suppressed errors, rerun with: -s
==159118== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### Problem in errors.c
In the file errors.c, the stringOnHeap was created using malloc function to 
provide a heap space, but this space is not freed after use. no_errors.c added 
the following code
```
free(stringOnHeap);
```
to free the heap space taken by stringOnHeap, so there is no errors using Valgrind.

### Who did I work with?
Only myself.

### How long did this take you?
About 20 minutes.
