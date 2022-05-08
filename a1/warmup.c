#include <stdio.h>

/*
 * Prints the victory message with a newline.
 */
void print_victory()
{
    printf("VICTORY!\n");
}

/*
 * Prints the victory message with a newline three times.
 */
void print_victory_three_times1()
{
    printf("VICTORY!\nVICTORY!\nVICTORY!\n");
}

/*
 * Prints the victory message with a newline three times using a for loop.
 */
void print_victory_three_times2()
{
    const int PRINT_TIMES = 3;
    for (int i = 0; i < PRINT_TIMES; i++)
    {
        print_victory();
    }
}

/*
 * Main function to print three victory messages with a newline.
 */
int main()
{
    print_victory_three_times1();
    print_victory_three_times2();
    return 0;
}
