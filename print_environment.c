#include "main.h"
#include "lists.h"
#include "kkshell.h"

/**
 * _printenv - Prints the environment variables.
 * @params: Pointer to the parameter struct containing shell variables.
 *
 * Prints all the environment variables stored in params->env_head.
 * If no environment variables exist, prints an error message.
 *
 * Return: void
 */
void _printenv(param_t *params)
{
	if (params->tokCount != 1)
	{
		_printf("env: %s: No such file or directory\n",
			params->args[1]);
		params->status = 2;
		return;
	}

	print_environment_list(params->env_head);
	params->status = 0;
}

/**
 * print_environment_list - Prints the environment variables.
 * @head: Pointer to the head of the environment list.
 *
 * This function takes in a pointer to the head of the environment list and
 * recursively prints the list in reverse order. For each node in the list,
 * the function checks if the str member is not NULL, and if so, it prints
 * the variable name and value in the format "name=value".
 */
void print_environment_list(list_t *head)
{
	if (head)
	{
		print_environment_list(head->next);
		if (head->str)
			_printf("%s=%s\n", head->str, head->val);
	}
}

