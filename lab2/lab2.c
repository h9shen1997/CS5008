#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Changes all the values in the array that are greater than the ceiling to
 * ceiling value.
 */
void crop_hi(int *arr, int len, int ceiling)
{
    int index = 0;
    while (index < len)
    {
        if (arr[index] > ceiling)
        {
            arr[index] = ceiling;
        }
        index++;
    }
}

/*
 * Swaps the middle element with the last element of the array.
 */
void swap_mid_back(int *arr, int len)
{
    int mid = len / 2;
    int temp = arr[len - 1];
    arr[len - 1] = arr[mid];
    arr[mid] = temp;
}

/*
 * Changes all the digits in the string to * character.
 */
void redact(char *str)
{
    int index = 0;
    while (str[index] != '\0')
    {
        if (isdigit(str[index]))
        {
            str[index] = '*';
        }
        index++;
    }
}

/*
 * Main function. 
 */
int main()
{
    int len = 7;
    int arr1[] = {1, 2, 3, 5, 6, 7, 9};

    int index = 0;
    printf("The original array is: \n");
    while (index < len)
    {
        printf("%d ", *(arr1 + index));
        index++;
    }
    printf("\n");

    crop_hi(arr1, len, 4);

    index = 0;
    printf("After crop_hi, the array is: \n");
    while (index < len)
    {
        printf("%d ", *(arr1 + index));
        index++;
    }
    printf("\n\n");

    int arr2[] = {1, 2, 3, 5, 6, 7, 9};
    index = 0;
    printf("The original array is: \n");
    while (index < len)
    {
        printf("%d ", *(arr2 + index));
        index++;
    }
    printf("\n");

    swap_mid_back(arr2, len);
    index = 0;
    printf("After swap_mid_back, the array is: \n");
    while (index < len)
    {
        printf("%d ", *(arr2 + index));
        index++;
    }

    printf("\n\n");

    char str[] = "a0fgh3j7k3j2";
    printf("The original string is: %s\n", str);
    redact(str);
    printf("After redact, the string is: %s\n", str);
    return 0;
}
