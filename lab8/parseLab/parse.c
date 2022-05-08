#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 80
#define ARGSNUM 1

/**
 * Prints the command line token separated by space without checking for
 * correctness.
 *
 * INPUT: command line token string
 **/
void PrintToken(char* cmdline) {
    // Remove the trailing newline character first.
    cmdline[strcspn(cmdline, "\n")] = '\0';

    // Get the first token within the string and continuously check if there is
    // any remaining tokens.
    char* token = strtok(cmdline, " ");
    while (token != NULL) {
        fprintf(stdout, "%s\n", token);
        token = strtok(NULL, " ");
    }
}

int main(int argc, char** argv) {
    if(argc != ARGSNUM) {
        fprintf(stdout, "The number of cmd arguments should be %d.\n", ARGSNUM);
        return EXIT_FAILURE;
    }
    char cmdline[MAXLINE];
    PrintToken(argv[1]);
    return EXIT_SUCCESS;
}