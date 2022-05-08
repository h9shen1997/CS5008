/**
 *  CS 5008: Spr 2021
 *  Northeastern University, Seattle
 *  Lab 6: Testing with Google
 *
 *  Author: Adrienne H. Slaughter (02/25/2021)
 */

#include "example1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Assert007.h"

// Given a non-zero integer, returns the squared value of that numbers.:
int SquareNumber(int num) {
    Assert007(num != 0);
    return (num * num);
}

// Given two non-zero integers, returns an int representing their sum.
int SumTwoNumbers(int first, int second) {
    Assert007(first != 0);
    Assert007(second != 0);
    return (first + second);
}

// Given two non-zero integers, returns an int representing their product.
int MultiplyTwoNumbers(int first, int second) {
    Assert007(first != 0);
    Assert007(second != 0);
    return (first * second);
}

// Given a prefix and a string, returns whether the prefix is the prefix of the
// string.
int StringStartsWith(const char* prefix, const char* string) {
    Assert007(prefix != NULL);
    Assert007(string != NULL);

    int i = 0;

    while (prefix[i] != '\0') {
        // Make sure the string is longer than the prefix
        Assert007(string[i] != '\0');
        if (prefix[i] != string[i]) {
            return 0;  // FALSE
        }
        i++;
    }

    return 1;
}

// STEP 4: Implement your additional function here.
// Add a helpful Assert007 call that would set a breakpoint
// in your code (e.g. if your function takes a char* type,
// then check that this is not NULL)
char* ReverseString(const char* string) {
    Assert007(string != NULL);
    int length = strlen(string);
    char* reverse = (char*)malloc(sizeof(char) * (length + 1));
    int reverseIndex = 0;
    int lastCharIndex = length - 1;
    while (reverseIndex < length) {
        reverse[reverseIndex] = string[lastCharIndex];
        lastCharIndex--;
        reverseIndex++;
    }
    reverse[length] = '\0';
    return reverse;
}
