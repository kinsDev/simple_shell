#ifndef MY_SHELL_H
#define MY_SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include "lists.h"

/**
 *Description: This structures hold all variables that passed
 *@lineCount: total line of input
 *@args: array of arguments
 *@tokCount: num of tokens in a line input
 *@nextCommand: the next command to process
 *@status: run command return status
 *@argsCap: num of arguments the args array can hold
 *struct param_s - structure used to hold all shell variables needed
 *@env_head: singly linked list of environment vars
 *@alias_head: singly linked list of aliases
 *@buffer: input buffer
 *
 *@argv: command line argument from main function
 *
 */
typedef struct param_s
{

	list_t *alias_head;
	char **argv;
	list_t *env_head;
	char *buffer;
	char **args;
	int status;
	char *nextCommand;
	unsigned int tokCount;
	unsigned int argsCap;
	unsigned int lineCount;
	
} param_t;

/**
 * struct op - a buildin function
 * @name: buildin
 * @func: buildin function
 */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;

int process_string(param_t *);

char *_strdup(char *);

char *_strcpy(char *dest, const char *src);

int _getline(param_t *);

int _strcmp(char *, char *);

int _strcmp_n(char *, char *, int n);

char *_strtok(char *str, char *delim, char **savePtr);

void run_command(param_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void _printenv(param_t *);

void sigint_handler(int);

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

void print_list_env(list_t *);

void print_list_alias(list_t *);

void free_params(param_t *params);

void write_error(param_t *params, char *msg);

void _clear(param_t *params);
#endif
