#include <stdio.h>
#include <stdlib.h>

#define OFFSET 2

/*
 * Helper function to print a character by the number of times specified.
 */
void print_length_of_char(int times, char symbol)
{
    for (int i = 0; i < times; i++)
    {
        printf("%c", symbol);
    }
}

/*
 * Prints a rectangle with the specified width and height.
 */
void print_rectangle(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        printf("The width and height of the rectangle must be greater than 0.");
        exit(1);
    }
    char normal_symbol = '-';
    char fill_symbol = ' ';
    int offset_height = height - OFFSET;
    int offset_width = width - OFFSET;

    print_length_of_char(width, normal_symbol);
    printf("\n");
    for (int i = 0; i < offset_height; i++)
    {
        print_length_of_char(1, normal_symbol);
        print_length_of_char(offset_width, fill_symbol);
        print_length_of_char(1, normal_symbol);
        printf("\n");
    }
    print_length_of_char(width, normal_symbol);
    printf("\n\n");
}

/*
 * Prints a fancy rectangle.
 */
void print_fancy_rectangle(int width, int height, char symbol, int fill)
{
    if (width <= 0 || height <= 0)
    {
        printf("The width and height of the rectangle must be greater than 0.");
        exit(1);
    }
    char fill_symbol = fill ? symbol : ' ';
    int offset_height = height - OFFSET;
    int offset_width = width - OFFSET;

    print_length_of_char(width, symbol);
    printf("\n");
    for (int i = 0; i < offset_height; i++)
    {
        print_length_of_char(1, symbol);
        print_length_of_char(offset_width, fill_symbol);
        print_length_of_char(1, symbol);
        printf("\n");
    }
    print_length_of_char(width, symbol);
    printf("\n\n");
}

/*
 * Main function to print out rectangles.
 */
int main()
{
    const int WIDTH = 5;
    const int HEIGHT = 4;
    print_rectangle(WIDTH, HEIGHT);
    print_fancy_rectangle(WIDTH, HEIGHT, '+', 0);
    print_fancy_rectangle(WIDTH, HEIGHT, '*', 1);
    return 0;
}
