#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Double the value using pointer to int
void doubler(int *x)
{
    *x *= 2;
}

// Cast away the const
void printPointerTarget(const int *p)
{
    *((int *)p) = 5;
    printf("%d\n", *p);
}

int sumArray(int n, const int a[])
{
    const int *an;
    int sum = 0;
    an = a + n;
    while (a < an)
    {
        sum += *a++;
    }
    return sum;
}

// Main function to do some pointer practice
int main(int argc, char **argv)
{
    // practice pointer assignment
    int n;
    int *p;
    int *q;

    p = &n;
    q = p;

    *p = 2;
    assert(n == 2);
    assert(*q == 2);

    *p = *p + *p;
    assert(n == 4);
    assert(*q == 4);

    (*p)++;
    assert(n == 5);
    assert(*q == 5);

    int y = 1;
    doubler(&y);
    assert(y == 2);

    int a[3];

    // practice setting and getting array using pointers
    *a = 12;
    *(a + 1) = 13;
    *(a + 2) = 14;
    int firstValue = 12;
    int initializedLengthOfArray = 3;
    int expectedSum = 39;

    for (int i = 0; i < initializedLengthOfArray; i++)
    {
        assert((firstValue + i) == *(a + i));
    }

    assert(expectedSum == sumArray(initializedLengthOfArray, a));

    return EXIT_SUCCESS;
}