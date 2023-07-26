#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
extern char **environ;

char* promptInput(const char* prompt);
void tokenizeInput(char* input);
void execute_command(char *command);
void print_environment();


#endif
