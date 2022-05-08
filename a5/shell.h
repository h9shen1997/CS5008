#ifndef SHELL_H
#define SHELL_H
#define MAX_ARGS 5
#define LINE_BUFFER_SIZE 2000
#define MAX_PER_LINE 80
#define TRUE 1
#define FALSE 0
#include <signal.h>
#include <stdio.h>

int CheckIfZeroArgument(char*, char*);
int CheckAllSpacesOrEmpty(char*);
int CheckGuess(int, int);
int CheckIsNumber(char* input);
int CheckLessThanMaxPerLine(char*);
int BuiltinCommand(char**);
int GenerateRandomNumWithinRange(int, int);
void CD(char*);
void Exit(char*);
void Help(char*);
void Game(char*);
void ReadValue(int*, const char*);
void StartGame();
void Eval(char*);
pid_t Fork(void);
char* Fgets(char*, int, FILE*);

#endif
