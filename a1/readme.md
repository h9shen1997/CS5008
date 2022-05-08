# Homework a1
## How to build and run the code
**Command to compile the code:**
```
gcc -o assignment1 assignment1.c
gcc -o warmup warmup.c
``` 

**Command to run the code:**
```
./assignment1
./warmup
```

## Directory content
There are three files in the directory, 
1.assignment.c 
2.warmup.c 
3.readme.md.
assignment.c includes the methods to print two types of rectangles to the 
terminal. warmup.c contains two methods to print a VICTORY message and three
newlines after that. readme.md describes the details of this homework.

## Examples of input and output
There is no input for warmup.c. The output of this file is the following:
```
VICTORY!
VICTORY!
VICTORY!
```
The first way to print was using three "VICTORY!\n" together:
```
printf("VICTORY!\nVICTORY!\nVICTORY!\n");
```
The second way to print was using the for loop:
```
const int PRINT_TIMES = 3;
for (int i = 0; i < PRINT_TIMES; i++)
{
    print_victory();
}
```
The second way is better because it reduces repeated code and utilize the idea
of for loop in c.

The input to function print_rectangle is specified width and height, for 
example, width=5, height=4. The output using the specified values was:
```
-----
-   -
-   -
-----
```

The input to the function print_fancy_rectangle is specified width, height, 
symbol, and whether filled or not, for example, width=5, height=4, symbol='*',
fill=1. The output using the specified values was:
```
*****
*****
*****
*****
```

## How much time spent and what went well
I spent about 40 minutes to complete the assignments. Everything went well.
