#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/**
 * _setenv - Set or update an environment variable with the given name and value.
 * @params: Pointer to the shell parameters struct.
 */
void set_env_variable(param_t *params)
{
    char *tmp = NULL;
    char *name = params->args[1];
    char *value = params->args[2];
    list_t *current = params->env_head;

    if (params->tokCount != 3)
    {
        /* Invalid number of arguments */
        params->status = 0;
        return;
    }

    while (current)
    {
        if (_strcmp(name, current->str) == 0) /* Environment variable exists */
        {
            /* Update existing environment variable */
            tmp = current->val;
            free(tmp);
            current->val = _strdup(value);
            if (!current->val)
            {
                /* Memory allocation error */
                write(STDERR_FILENO, "setenv: memory allocation error\n", 30);
                exit(-1);
            }
            current->valLen = _strlen(value);
            params->status = 0;
            return;
        }
        current = current->next;
    }

    /* Environment variable does not exist, add it to the list */
    params->env_head = add_node(&(params->env_head), name, value);
    params->status = 0;
}

/**
 * _unsetenv - Remove an environment variable with the given name from the list.
 * @params: Pointer to the shell parameters struct.
 */
void unset_env_variable(param_t *params)
{
    char *name = params->args[1];
    list_t *prev = NULL;
   

