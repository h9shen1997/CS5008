# Assignment 6: Finding Anagrams with Hashtables

## Files included
* ```words.txt```: The word file you need to read in to find anagrams with. 
* ```Hashtable.h```: Generic hashtable header.
* ```Hashtable.c```: Generic hashtable implementation.
* ```LinkedList.h```: Contains API for a generic LinkedList implementation.
* ```LinkedList.c```: Generic LinkedList implmentation.
* ```LinkedListPriv.c```: Hide detailed linked list node implementation.
* ```LinkedListPriv.h```: Hide detailed linked list node header.
* ```Main.c```: The file for anagram algorithm using hashtable.
* ```Makefile```: Generic starting Makefile
* ```test_hashtable.cc```: A starting test file for you to use to test your hashtable implementation. 
* ```release-1.8.0.tar.gz```: google c/c++ test framework file.

## Which version of hashtable I chose:
I have chosen the generic hashtable using chaining. The hashtable key is hashed from the string provided, and the value is a linkedlist. The value linkedlist contains a another HTKeyValuePair in which the key is the hash key, and the value is a list of anagram. 

## Valgrind checking:
I have used Valgrind to check for memory leakage. There is no memory leak at all. Every malloc has been freed.
Here is a screenshot of:
```
==201148== 
==201148== HEAP SUMMARY:
==201148==     in use at exit: 0 bytes in 0 blocks
==201148==   total heap usage: 7,524,383 allocs, 7,524,383 frees, 228,865,648 bytes allocated
==201148== 
==201148== All heap blocks were freed -- no leaks are possible
==201148== 
==201148== For lists of detected and suppressed errors, rerun with: -s
==201148== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## How to run my program:
- To run the test:
```make test_suite```
- To run the anagram algorithm and generate output:
```make run```
*important!* Only words with anagram are generated. Words without anagram are ignored.
- To run anagram algorithm with valgrind:
```valgrind --leak-check=full ./main```
- Or you can run both using:
```make all```

## Example output:
example anagrams:
```
dicerous discoure 
girtlines relisting tirelings 
atmogenic geomantic 
creedalist decaliters 
dolt told 
meatworks teamworks workmates 
amusing nuagism 
dewooling inglewood 
clasps scalps 
intertwin inwritten 
clonicotonic tonicoclonic 
conduit duction noctuid 
attern natter ratten tarten 
ruinousnesses unseriousness 
canova vacona 
```

Test result:
```
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Hashtable
[ RUN      ] Hashtable.Create
[       OK ] Hashtable.Create (0 ms)
[ RUN      ] Hashtable.AddOneRemoveOne
[       OK ] Hashtable.AddOneRemoveOne (0 ms)
[ RUN      ] Hashtable.AddOneElemDestroy
[       OK ] Hashtable.AddOneElemDestroy (0 ms)
[ RUN      ] Hashtable.AddOneElemTwoTimes
[       OK ] Hashtable.AddOneElemTwoTimes (0 ms)
[ RUN      ] Hashtable.AddMultipleItems
[       OK ] Hashtable.AddMultipleItems (0 ms)
[ RUN      ] Hashtable.LookupInHashtable
[       OK ] Hashtable.LookupInHashtable (0 ms)
[ RUN      ] Hashtable.TwoElemsOneBucket
[       OK ] Hashtable.TwoElemsOneBucket (0 ms)
[----------] 7 tests from Hashtable (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 7 tests.
```

## Meme posted:
I have posted a meme on piazza.

## Resources used:

* https://medium.com/basecs/hashing-out-hash-functions-ea5dd8beb4dd (Hash Functions)
* https://medium.com/basecs/taking-hash-tables-off-the-shelf-139cbf4752f0?source=---------17----------------------- (Hash Tables, generally)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#hashTables (Hashtables in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#File_IO  (Reading a file in C)
* http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#functionPointers (Function Pointers, for more challenge)

## Challenges encountered:
Jesus, this homework is so time consuming and implementing the generic hashtable is hard, especially to manage memory well and be able to free every memory allocated. I honestly hope Drew can teach more deeply about C programming and help us understand better before he giving us such a hard assignment. 

## Time taken:
30 hours
