## Homework a2 readme

### Files in the homework
1. readme.md
2. Makefile
3. pointers.c
4. a2.c
5. a2.h
6. a2_test.c

### External library the files rely on
1. **a2.c** relies on stdio.h, stdlib.h, time.h, assert.h, ctype.h, string.h, and a2.h.
2. **a2_test.c** relies on stdio.h, stdlib.h, time.h and a2.h
3. **pointers.c** relies on stdio.h, stdlib.h and assert.h
All of these libraries can be imported using 
```
#include <library_name>
```

### Assumption made
I assumed that the first and last name were always provided when writing the assignment,
though the middle name could be provided optionally. If any of the testing format character
was not valid, I printed out the message "Please provide the correct format character!" instead of a blank output. This would inform the user of the correct program usage.

### How to run the program
Since this homework has a **Makefile**, simply go to the homework directory and 
type 
```
make
```
or 
```
make -f Makefile
```
Then, the Makefile will compile the homework files using gcc compiler.
The output file will be named as a2. It can also be run itself using
```
./a2
```

### Input and Output
The **pointers.c** has no input and output. I have used the **assert** library to 
test the functional correctness on the fly using
```
assert(condition)
```

The **a2_test.c** is used to test the implementation of methods to manipulate names.
**a2.c** contains the implementation of Name struct and its related methods. An 
example output of the test using the provided a2_test.c is below. **Notice that the name output is formatted, so that the first character is capitalized and the rest of the characters are all lowercase. This is done for the bonus section.**
```
Test #1: Print Big

Alyssa Mary Antle

Ben Ivan Bitdiddle

Daniel Diamond


--------------------------------

Test #2: Print Last

Bitdiddle, Ben

Diamond, Daniel


--------------------------------

Test #3: Print Reg

Cassie Charstrup

Daniel Diamond


--------------------------------

Test #4: Print Mid

Daniel Diamond

Alyssa M. Antle


--------------------------------

Test #5: Print Small

Daniel

Ben


--------------------------------

Test #6: Print FormatName

Alyssa Mary Antle

Antle, Alyssa

Alyssa Antle

Alyssa M. Antle

Alyssa

Daniel Diamond

Diamond, Daniel

Daniel Diamond

Daniel Diamond

Daniel


--------------------------------

Test #7: Print FillName

Alyssa Mary Antle

Antle, Alyssa

Ben I. Bitdiddle

Anya

Please provide the correct format character!


--------------------------------

feel free to add your own!
```

### External resources
The way I implemented the **FillName** method was to redirect the standard output to the string buffer. After realizing that puts() method print a string to the standard output, I refered to this post on StackOverflow to learn how to redirect stdout to a string buffer. *Link*: https://stackoverflow.com/questions/14428406/redirect-output-from-stdout-to-a-string
The code is as below:
```
freopen("/dev/null", "a", stdout);
setbuf(stdout, dest);
FormatName(name, format);
freopen("/dev/tty", "a", stdout);
```

### What was tricky?
I also noticed that the string given in the test are all **string literals**, and they are **immutable** in c. In order to modify a string in c, we need to declare a string buffer either using an array of characters or a character pointer. Thus, I used the method snprintf() to first copy the string literals into a string buffer using pointer. Then, I formatted the string and returned a pointer to the string on the heap. After the string printout, I freed all the pointers to the strings on heap and free the memory to prevent memory leak.

### Time spent
About 1.5 hours.