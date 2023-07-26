#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE
#include <stdio.h>
#include "lists.h"

/**
 * struct param_s - structure used to hold all shell variables needed
 * @argv: command line argument from main function
 * @buffer: input buffer
 * @args: array of arguments
 * @nextCommand: the next command to process
 * @argsCap: num of arguments the args array can hold
 * @lineCount: total line of input
 * @tokCount: num of tokens in a line input
 * @status: run command return status
 * @env_head: singly linked list of environment vars
 * @alias_head: singly linked list of aliases
 * Description: This structure holds all variables that are passed into
 * other functions.
 */
typedef struct param_s
{
    char **argv;
    char *buffer;
    char **args;
    char *nextCommand;
    unsigned int argsCap;
    unsigned int lineCount;
    unsigned int tokCount;
    int status;
    list_t *env_head;
    list_t *alias_head;
} param_t;

/**
 * struct op - a built-in function
 * @name: built-in name
 * @func: pointer to built-in function
 */
typedef struct op
{
    char *name;
    void (*func)(param_t *);
} op_t;

/**
 * init_param - Initializes the param_t structure and its members.
 * @argv: The command-line arguments.
 * @env: The environment variables.
 *
 * Return: A pointer to the initialized param_t structure.
 */
param_t *init_param(char **argv, char **env);

/**
 * print_environment_list - Prints the environment variables.
 * @head: Pointer to the head of the environment variables list.
 */
void print_environment_list(list_t *head);

/**
 * print_all_aliases - Prints all aliases.
 * @params: Pointer to the param_t structure.
 */
void print_all_aliases(param_t *params);

/**
 * free_alias_list - Frees the memory allocated for the alias list.
 * @head: Pointer to the head of the alias list.
 */
void free_alias_list(list_t *head);

#endif /* _MAIN_H_ */

