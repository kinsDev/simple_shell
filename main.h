#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* declaring the execmd function that takes in the execve in the execute file */
void execmd(char **argv);
char *get_location(char *command);

/* Function prototypes for get_line.c */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_input_line(char **lineptr, size_t *n, FILE *stream);

#endif
