#include "main.h"
#include "lists.h"
#include "kkshell.h"
#include <stdlib.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not found.
 *
 * Description:
 * This function searches for an environment variable with the given name in the
 * linked list of environment variables contained in the parameter structure.
 * If a match is found, the value associated with that variable is duplicated
 * and returned as a new string. If no match is found, the function returns NULL.
 */
char *_getenv(char *name, param_t *params)
{
    list_t *current_node = params->env_head;

    while (current_node)
    {
        if (!_strcmp(name, current_node->str))
            return (_strdup(current_node->val));

        current_node = current_node->next;
    }

    // Return NULL if the environment variable is not found
    return (NULL);
}

/**
 * _printenv - Prints the list of environment variables.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: None
 *
 * Description:
 * This function prints the linked list of environment variables contained in the
 * parameter structure.
 */
void _printenv(param_t *params)
{
    print_environment_list(params->env_head);
}

