#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include "lists.h"

/**
 * MAIN_H - all our header files are stored here
 *
 * Custom data structure to hold all shell variables needed
 */
typedef struct param_s
{
    char **argv;               /* Command line argument from main function */
    char *buffer;              /* Input buffer */
    char **args;               /* Array of arguments */
    char *nextCommand;         /* The next command to process */
    unsigned int argsCap;      /* Number of arguments the args array can hold */
    unsigned int lineCount;    /* Total line of input */
    unsigned int tokCount;     /* Number of tokens in a line input */
    int status;                /* Return status of the run command */
    list_t *env_head;          /* Singly linked list of environment vars */
    list_t *alias_head;        /* Singly linked list of aliases */
} param_t;

/* Custom data structure for built-in commands */
typedef struct op
{
    char *name;                /* Built-in name */
    void (*func)(param_t *);   /* Pointer to built-in function */
} op_t;

/* Function prototypes */
int process_string(param_t *params);
char *_strdup(char *str);
char *_strcpy(char *dest, const char *src);
int _getline(param_t *params);
int _strcmp(char *s1, char *s2);
int _strcmp_n(char *s1, char *s2, int n);
char *_strtok(char *str, char *delim, char **savePtr);
void run_command(param_t *params);
void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);
void _printenv(param_t *params);
void sigint_handler(int sig);
char *_getenv(char *name, param_t *params);
void _setenv(param_t *params);
void _unsetenv(param_t *params);
char *get_file(param_t *params);
void (*get_builtin(param_t *params))(param_t *);
void _myExit(param_t *params);
void _cd(param_t *params);
void _alias(param_t *params);
void set_alias(char *name, param_t *params);
void make_alias(char *name, char *val, param_t *params);
void print_alias(char *name, param_t *params);
void print_all_aliases(param_t *params);
void print_list_env(list_t *head);
void print_list_alias(list_t *head);
void free_params(param_t *params);
void write_error(param_t *params, char *msg);
void _clear(param_t *params);

#endif /* MY_SHELL_H */

