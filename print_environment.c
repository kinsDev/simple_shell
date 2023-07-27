#include "main.h"
#include "lists.h"
#include "kkshell.h"

/**
 * _printenv - prints the environment variables
 * @params: parameters containing the environment list
 *
 * This function prints all the environment variables stored in params->env_head.
 * If there are no environment variables, it prints an error message.
 *
 * Return: void
 */
void _printenv(param_t *params)
{
    if (params->tokCount != 1)
    {
        /* Invalid usage of the _printenv command */
        _printf("env: %s: No such file or directory\n", params->args[1]);
        params->status = 2;
        return;
    }
    
    /* Print the environment variables */
    print_list_env(params->env_head);
    params->status = 0;
}

/**
 * print_list_env - print the environment variables in reverse order
 * @head: pointer to the head of the environment list
 *
 * This function takes in a pointer to the head of the environment list and
 * recursively prints the list in reverse order. For each node in the list,
 * the function checks if the str member is not NULL, and if so, it prints
 * the variable name and value in the format "name=value".
 *
 * Note: The environment list is assumed to be in reverse order, so this function
 * prints the variables in the correct order.
 */
void print_list_env(list_t *head)
{
    if (head)
    {
        /* Recursively print the next node */
        print_list_env(head->next);
        
        /* Print the variable name and value */
        if (head->str)
            _printf("%s=%s\n", head->str, head->val);
    }
}

