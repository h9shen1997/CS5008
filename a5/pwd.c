#include "shell.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Checks if the argument provided for the command is nothing or empty
 * spaces.
 *
 * @param input the argument list, which should be null or empty spaces.
 * @param command the command name.
 *
 * @return int TRUE if zero argument is satisfied, otherwise FALSE.
 */
int CheckIfZeroArgument(char* input, char* command) {
    char* buffer = strtok(input, " ");
    if (buffer != NULL) {
        fprintf(stderr, "%s does not take any argument.\n", command);
        return FALSE;
    }
    return TRUE;
}

/**
 * @brief Outputs the current working directory.
 *
 * @param the argument list of pwd, which should be null or empty spaces.
 */
void PWD(char* input) {
    if (!CheckIfZeroArgument(input, "pwd")) {
        return;
    }
    char cwd[MAX_PER_LINE];

    // Get the current working directory. If it fails, exit with failure code.
    // Otherwise, print to the stdout the directory name.
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        fprintf(stderr, "Error getting the current working directory.\n");
        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "%s\n", cwd);
    }
}

int main(int argc, char** argv) {
    PWD(argv[1]);
    return EXIT_SUCCESS;
}
