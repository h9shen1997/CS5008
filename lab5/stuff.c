/**
 *  CS 5008: Spr 2022
 *  Northeastern University, Seattle
 *  Lab 5: Style and cLint
 *
 */
#include "stuff.h"

#include <stdio.h>

const kNumsToAverage = 3;

void DoStuff() {
    int i;
    int nums[kNumsToAverage];
    for (i = 0; i < kNumsToAverage; i++) {
        printf("Enter number %d of %d: ", i, kNumsToAverage);
        scanf("%d", &nums[i]);
    }

    int sum = 0;
    for (i = 0; i < kNumsToAverage; i++) {
        sum += nums[i];
    }
    printf(
        "The average of the values you entered is %.2f, but don't take my word "
        "for it.\n",
        (double)sum / kNumsToAverage);

    return;
}
