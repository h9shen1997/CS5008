#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "a2.h"

#define BUFFER_SIZE 50
#define SINGLE_CHAR_LENGTH 1

// Capitalize the first character of a string and make all other characters
// lowercase.
//
// s: a pointer to a string literal
char *TransformWord(char *s)
{
    if (s == NULL || *s == '\0')
    {
        return NULL;
    }
    int len = strlen(s);
    char *buffer = (char *)calloc(len + 1, sizeof(char));
    snprintf(buffer, len + 1, "%s", s);
    *buffer = toupper(*buffer);

    int i;
    for (i = 1; *(s + i) != '\0'; i++)
    {
        *(buffer + i) = tolower(*(buffer + i));
    }
    *(buffer + len) = '\0';
    return buffer;
}

// Print the string <first> <middle> <last>
// e.g. if first = "Ben", middle = "Ivan",
// and last = "Bitdiddle, then print:
// "Ben Ivan Bitdiddle".
//
// If the middle name is NULL, then print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Big(Name *name)
{
    char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    assert(buffer);
    char *p_first = TransformWord(name->first);
    char *p_middle = TransformWord(name->middle);
    char *p_last = TransformWord(name->last);

    strcat(buffer, p_first);
    strcat(buffer, " ");
    if (p_middle != NULL)
    {
        strcat(buffer, p_middle);
        strcat(buffer, " ");
    }
    strcat(buffer, p_last);

    puts(buffer);
    free(buffer);
    free(p_first);
    free(p_middle);
    free(p_last);
}

// Print the string <last>, <first>
// e.g. if first = "Ben", middle = "Ivan",
// and last = "Bitdiddle, then print:
// "Bitdiddle, Ben".
//
// name: a pointer to a Name
void Last(Name *name)
{
    char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    assert(buffer);
    char *p_first = TransformWord(name->first);
    char *p_last = TransformWord(name->last);

    strcat(buffer, p_last);
    strcat(buffer, ", ");
    strcat(buffer, p_first);
    puts(buffer);
    free(buffer);
    free(p_first);
    free(p_last);
}

// Print the string <first> <last>
// e.g. if first = "Ben", middle = "Ivan",
// and last = "Bitdiddle, then print:
// "Ben Bitdiddle".
//
// name: a pointer to a Name
void Reg(Name *name)
{
    char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    assert(buffer);

    char *p_first = TransformWord(name->first);
    char *p_last = TransformWord(name->last);

    strcat(buffer, p_first);
    strcat(buffer, " ");
    strcat(buffer, p_last);

    puts(buffer);
    free(buffer);
    free(p_first);
    free(p_last);
}

// Print the string <first> <middle-initial>. <last>
// e.g. if first = "Ben", middle = "Ivan",
// and last = "Bitdiddle, then print:
// "Ben I. Bitdiddle".
//
// If middle name is NULL, print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Mid(Name *name)
{
    char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    assert(buffer);

    char *p_first = TransformWord(name->first);
    char *p_middle = TransformWord(name->middle);
    char *p_last = TransformWord(name->last);

    char *middleFirstChar = (char *)calloc(SINGLE_CHAR_LENGTH + 1, sizeof(char));
    *(middleFirstChar + 1) = '\0';

    strcat(buffer, p_first);
    strcat(buffer, " ");
    if (p_middle != NULL && *p_middle != '\0')
    {
        *middleFirstChar = *p_middle;
        strcat(buffer, middleFirstChar);
        strcat(buffer, ". ");
    }
    strcat(buffer, p_last);

    puts(buffer);
    free(buffer);
    free(p_first);
    free(p_middle);
    free(p_last);
    free(middleFirstChar);
}

// Print the first name only.
// e.g. if first = "Ben", middle = "Ivan",
// and last = "Bitdiddle, then print:
// "Ben".
//
// name: a pointer to a Name
void Small(Name *name)
{
    char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    assert(buffer);
    char *p_first = TransformWord(name->first);

    strcat(buffer, p_first);

    puts(buffer);
    free(buffer);
    free(p_first);
}

// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
void FormatName(Name *name, char format)
{
    switch (tolower(format))
    {
    case 'b':
        Big(name);
        break;
    case 'l':
        Last(name);
        break;
    case 'r':
        Reg(name);
        break;
    case 'm':
        Mid(name);
        break;
    case 's':
        Small(name);
        break;
    default:
        puts("Please provide a correct format character!");
    }
}

// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest)
{
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, dest);
    FormatName(name, format);
    freopen("/dev/tty", "a", stdout);
}