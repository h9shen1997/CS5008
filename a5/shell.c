#include "shell.h"

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// All of the command names.
char* commands[] = {"cd", "help", "exit", "game"};

/**
 * @brief Checks if the argument provided for the command is nothing or empty
 * spaces.
 *
 * @param input the argument list, which should be null or empty spaces.
 * @param command the command name.
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
 * @brief Checks if the characters after the number are either empty or all
 * spaces to ensure only one number is provided.
 *
 * @param input the remaining character after the first number.
 * @return int TRUE if all the remaining characters are either empty or all
 * space, otherwise FALSE.
 */
int CheckAllSpacesOrEmpty(char* input) {
    if (input == NULL) return TRUE;
    while (*input != '\0') {
        if (!isspace(*input)) {
            return FALSE;
        }
        input++;
    }
    return TRUE;
}

/**
 * @brief Changes directory based on the provided path.
 *
 * @param input the directory to be changed to, which should only be one
 * argument.
 */
void CD(char* input) {
    char* dir = strtok(input, " ");
    char* rem;
    if ((rem = strtok(NULL, " ")) != NULL) {
        fprintf(stderr, "cd only takes one argument.\n");
        return;
    }
    if (input == NULL || dir == NULL) {
        dir = getenv("HOME");
    }
    if (chdir(dir) == -1) {
        fprintf(stderr, "No such directory as %s.\n", dir);
    }
}

/**
 * @brief Exits the current shell process.
 *
 * @param input the argument list of exit, which should be null or empty spaces.
 */
void Exit(char* input) {
    if (!CheckIfZeroArgument(input, "exit")) {
        return;
    }
    exit(0);
}

/**
 * @brief Outputs all the builtin commands of k-sea-shell.
 *
 * @param input the argument list of help, which should be null or empty spaces.
 */
void Help(char* input) {
    if (!CheckIfZeroArgument(input, "help")) {
        return;
    }
    int command_size = sizeof(commands) / sizeof(commands[0]);
    int i;
    for (i = 0; i < command_size; i++) {
        fprintf(stdout, "%s\n", commands[i]);
    }
}

/**
 * @brief Checks whether the given input is a single number without leading and
 * trailing spaces.
 *
 * @param input the command line input user provides.
 * @return int TRUE if the user input is a single number, FALSE otherwise.
 */
int CheckIsNumber(char* input) {
    if (input == NULL || *input == '\0') return FALSE;
    while (*input != '\0') {
        if (!isdigit(*input)) {
            return FALSE;
        }
        input++;
    }
    return TRUE;
}

/**
 * @brief Asks the user to provide a value. Reads and saves it.
 *
 * @param value a pointer to the value to be saved.
 * @param message info message to ask the user.
 */
void ReadValue(int* value, const char* message) {
    while (TRUE) {
        // Get the user input from stdin.
        fprintf(stdout, "%s", message);
        char* input = NULL;
        size_t length = 0;
        getline(&input, &length, stdin);
        // Remove the ending newline character and replace it with null
        // terminator for string.
        input[strcspn(input, "\n")] = '\0';

        // Remove leading whitespace if there is any
        char* number = strtok(input, " ");
        char* rem = strtok(NULL, "");

        // Check if the first non-whitespace string is a number and check if all
        // the characters after this first number string are all white space or
        // simply empty to make sure only one number is provided.
        if (!CheckIsNumber(number) || !CheckAllSpacesOrEmpty(rem)) {
            fprintf(stdout, "Please enter a single number.\n");
            continue;
        }
        *value = atoi(input);
        break;
    }
}

/**
 * @brief Checks whether the user has guessed the correct res and inform them
 * what to do.
 *
 * @param guess user's guess.
 * @param res the correct result.
 * @return int TRUE if the user has guessed the result, FALSE otherwise.
 */
int CheckGuess(int guess, int res) {
    if (guess == res) {
        fprintf(stdout, "Congrats, you got it right!\n");
        return TRUE;
    } else if (guess < res) {
        fprintf(stdout, "Guess higher.\n");
    } else {
        fprintf(stdout, "Guess lower.\n");
    }
    return FALSE;
}

/**
 * @brief Generates a random integer within the lower and upper bound,
 * inclusive.
 *
 * @param lower the lower bound.
 * @param upper the upper bound.
 * @return int a random value between the lower and upper bound, inclusive.
 */
int GenerateRandomNumWithinRange(int lower, int upper) {
    return lower + (rand() % (upper + 1 - lower));
}

/**
 * @brief Starts the guessing game.
 */
void StartGame() {
    int lower, upper, guess;
    const char* lowerMessage = "Enter the lower bound: ";
    const char* upperMessage = "Enter the upper bound: ";
    const char* guessMessage = "Enter the guess: ";

    // Ask the user to provide a lower and upper bound for guessing, inclusive.
    while (TRUE) {
        ReadValue(&lower, lowerMessage);
        ReadValue(&upper, upperMessage);
        if (lower >= upper) {
            fprintf(stdout,
                    "Please make sure lower bound is less than upper bound.\n");
        } else {
            break;
        }
    }

    // A seeded random generator based on the time.
    srand(time(0));

    // Generate a random integer within the lower and upper bound, inclusive.
    int res = GenerateRandomNumWithinRange(lower, upper);

    // Ask the user for a guess and check if the user has guessed the correct
    // number.
    while (TRUE) {
        ReadValue(&guess, guessMessage);
        if (CheckGuess(guess, res)) {
            break;
        }
    }
}

/**
 * @brief Starts a builtin game.
 *
 * @param input the argument list of game, which should be null or empty spaces.
 */
void Game(char* input) {
    if (!CheckIfZeroArgument(input, "game")) {
        return;
    }
    StartGame();
}

// All command function pointers.
void (*command_functions[])(char*) = {CD, Help, Exit, Game};

/**
 * @brief Wrapper of fork(). Checks for fork errors and quits on error.
 *
 * @return the process id.
 */
pid_t Fork(void) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return pid;
}

/**
 * @brief Wrapper of fgets(). Checks and quits on Unix error.
 *
 * @param ptr buffer pointer.
 * @param n the length of buffer.
 * @param stream file stream to read from, i.e. stdin.
 * @return char* a pointer to the char buffer.
 */
char* Fgets(char* ptr, int n, FILE* stream) {
    char* rptr;
    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
        fprintf(stderr, "%s\n", "fgets error");
        exit(EXIT_FAILURE);
    }
    return rptr;
}

/**
 * @brief Executes the command if it is a builtin shell command.
 *
 * @param argv the argument list for the command.
 * @return int TRUE if the command is builtin, FALSE otherwise.
 */
int BuiltinCommand(char** argv) {
    // Loop through all the builtin commands
    int i;
    int command_size = sizeof(commands) / sizeof(commands[0]);
    for (i = 0; i < command_size; i++) {
        int res = strcmp(commands[i], argv[0]);
        if (res == 0) {
            // Call the right function with the rest of the arguments
            (*command_functions[i])(argv[1]);
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * @brief Modifies and evaluates the command line input from user.
 *
 * @param cmdline the command line input user typed.
 */
void Eval(char* cmdline) {
    // Remove the ending newline character and replace it with null terminator
    // for string.
    cmdline[strcspn(cmdline, "\n")] = '\0';

    char* argv[MAX_ARGS];    // Argument list for execve()
    char buf[MAX_PER_LINE];  // Hold modified command line
    pid_t pid;               // Process id

    strcpy(buf, cmdline);

    // Split buf into args, the first argument is the command, then the rest of
    // the command line arguments is one chunk.
    argv[0] = strtok(buf, " ");
    argv[1] = strtok(NULL, "");
    argv[2] = NULL;

    // Ignore empty lines
    if (argv[0] == NULL) return;

    // Check that the command/program exists in shell or create a child process
    // to run the program (execve). If the program is not found, alert that the
    // command is not found and exit with failure code 1.
    if (!BuiltinCommand(argv)) {
        pid = Fork();
        if (pid == 0) {
            int res = execvp(argv[0], argv);
            if (res < 0) {
                fprintf(stdout,
                        "Command not found--Did you mean something else?\n");
                exit(EXIT_FAILURE);
            }
        } else {
            // Wait for child process to finish.
            wait(NULL);
        }
    }
    // If the command is a builtin commands, do nothing because the if statement
    // has already executed it.
}

/**
 * @brief Checks if the command line input is less than or equal to 80
 * characters per line.
 *
 * @param cmdline the command line input.
 * @return int TRUE if the character is not more than 80, otherwise FALSE.
 */
int CheckLessThanMaxPerLine(char* cmdline) {
    if (strlen(cmdline) > MAX_PER_LINE) {
        fprintf(stderr,
                "The maximum input size on a given line is %d characters. "
                "Please try again!\n",
                MAX_PER_LINE);
        return FALSE;
    }
    return TRUE;
}

int main() {
    char cmdline[LINE_BUFFER_SIZE];  // command line buffer.
    while (TRUE) {
        // Print command prompt.
        printf("k-sea-shell> ");
        // Flush the stdin to make sure buffer is empty for next command.
        fflush(stdin);
        // Read input from user.
        Fgets(cmdline, LINE_BUFFER_SIZE, stdin);
        // Check if the command line input is not more than 80 characters, and
        // if it is not valid, print out a message and ask the user to input
        // again.
        if (!CheckLessThanMaxPerLine(cmdline)) continue;
        // If we get the eof, quit the program/shell.
        if (feof(stdin)) exit(0);
        // Otherwise, evaluate the input and execute.
        Eval(cmdline);
    }
    return EXIT_SUCCESS;
}
