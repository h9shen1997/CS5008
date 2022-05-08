#include "generic.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// START_NO_CHANGE
const char ALLOWED[] = "abcdefghijklmnopqrstuvwxyz1234567890";
const int nbAllowed = sizeof(ALLOWED) - 1;

typedef char Character;

char* generateRandomStr() {
    int size = rand() % 30;
    char* str = (char*)malloc((sizeof(Character) * size) + 1);
    int i, c;
    for (i = 0; i < size; i++) {
        c = rand() % nbAllowed;
        str[i] = ALLOWED[c];
    }
    str[size] = '\0';
    return str;
}

Strings* generateRandomStrings() {
    int size = rand() % 50;
    printf("creating string list of size %d\n", size);

    char** strs = (char**)malloc(sizeof(char*) * size);
    int i;
    for (i = 0; i < size; i++) {
        char* s = generateRandomStr();
        printf("inserting str %s\n", s);

        strs[i] = s;
    }
    Strings* result = (Strings*)malloc(sizeof(Strings));
    result->data = strs;
    result->size = size;

    return result;
}

void printStrings(Strings* strs) {
    int i;
    for (i = 0; i < strs->size; i++) {
        printf("string in strs is %s\n", strs->data[i]);
    }
}
// END_NO_CHANGE

int countChars(Strings strings) {
    char** data = strings.data;
    int size = strings.size;
    int i;
    int count = 0;
    for (i = 0; i < size; i++) {
        char* string = data[i];
        int j = 0;
        while (string[j] != '\0') {
            j++;
        }
        count += j;
    }
    return count;
}

int countStrings(Strings strings) { return strings.size; }

void freeStrings(Strings strs) {
    int size = strs.size;
    int i;
    char** data = strs.data;
    for (i = 0; i < size; i++) {
        char* string = data[i];
        free(string);
    }
    free(data);
}

int main() {
    srand(time(NULL));

    Strings* strs = generateRandomStrings();
    printStrings(strs);
    printf("The number of char are: %d\n", countChars(*strs));
    printf("The number of strings are: %d\n", countStrings(*strs));
    freeStrings(*strs);
    free(strs);
}
