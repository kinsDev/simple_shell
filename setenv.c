#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/**
 * _setenv - Sets or updates an environment variable.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function searches the environment list to find the environment variable name,
 * and sets it to the corresponding value string. If the variable does not exist,
 * a new variable with the provided name and value is added to the environment list.
 */
void _setenv(param_t *params)
{
    char *tmp = NULL;
    char *name = params->args[1];
    char *value = params->args[2];
    list_t *h = params->env_head;

    /* Check if the number of arguments is correct */
    if (params->tokCount != 3)
    {
        params->status = 0; /* Reset the status to indicate no error */
        return;
    }

    /* Loop through the environment list to find the variable */
    while (h)
    {
        if (_strcmp(name, h->str) == 0) /* Environment variable exists */
        {
            tmp = h->val;
            free(tmp); /* Free the old value */
            h->val = _strdup(value); /* Update the value */
            if (!h->val)
            {
                /* Handle memory allocation error */
                write(STDERR_FILENO, "setenv malloc error\n", 18);
                exit(-1);
            }
            h->valLen = _strlen(value);
            params->status = 0; /* Reset the status to indicate success */
            return;
        }
        h = h->next;
    }

    /* Environment variable does not exist, add a new variable */
    params->env_head = add_node(&(params->env_head), name, value);
    params->status = 0; /* Reset the status to indicate success */
}

/**
 * _unsetenv - Removes an environment variable.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function searches the environment list to find the environment variable name
 * and removes it from the list. If the variable is not found, nothing is done.
 */
void _unsetenv(param_t *params)
{
    char *name = params->args[1];
    list_t *prev = NULL;
    list_t *h = params->env_head;

    /* Check if the number of arguments is correct */
    if (params->tokCount != 2)
    {
        params->status = 0; /* Reset the status to indicate no error */
        return;
    }

    /* Loop through the environment list to find the variable */
    while (h)
    {
        if (_strcmp(name, h->str) == 0) /* Environment variable exists */
        {
            /* Remove the node from the list and free its memory */
            if (h == params->env_head)
                params->env_head = h->next;
            else
                prev->next = h->next;
            free(h->str);
            free(h->val);
            free(h);
            params->status = 0; /* Reset the status to indicate success */
            return;
        }
        prev = h;
        h = h->next;
    }

    params->status = 0; /* Reset the status to indicate success */
}

