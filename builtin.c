#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "kkshell.h"
#include "lists.h"
#include "main.h"

/**
 * get_builtin - Get built-in function
 * @params: Pointer to the param_t struct containing command parameters
 *
 * Description: Searches for a built-in function based on the first argument
 * in the param_t struct. Returns a function pointer to the corresponding
 * built-in function if found, or NULL if not found.
 *
 * Parameters:
 *   - @params: The param_t struct containing command parameters.
 *
 * Return: Function pointer to the built-in function. NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)
{
    /* Define an array of built-in functions and their corresponding names */
    op_t ops[] = {
        {"exit", _myExit},          /* Function to exit the shell */
        {"clear", _clear},          /* Function to clear the screen */
        {"env", _printenv},         /* Function to print the environment variables */
        {"setenv", _setenv},        /* Function to set an environment variable */
        {"cd", _cd},                /* Function to change the current directory */
        {"unsetenv", _unsetenv},    /* Function to unset an environment variable */
        {"alias", _alias},          /* Function to define an alias for a command */
        {NULL, NULL},               /* Sentinel value to mark the end of the array */
    };

    /* Pointer to traverse the array of built-in functions */
    op_t *op = ops;

    /* Search for the appropriate built-in function */
    while (op->name)
    {
        /* Compare the input command with the names of the built-in functions */
        if (!_strcmp(params->args[0], op->name))
            return (op->func); /* Return the corresponding function pointer */
        op++;
    }

    /* Return NULL if no built-in function is found */
    return (NULL);
}

