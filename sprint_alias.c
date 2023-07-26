#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/**
 * print_alias - Prints the value of an alias, if it exists.
 * @name: Name of the alias to print.
 * @params: Parameter struct containing the alias list.
 *
 * Description: This function searches the alias list stored in the parameter
 * struct `alias_head` with the given `name`. If the alias is found, its value
 * is printed to stdout. If the alias is not found, an error message is printed
 * to stderr.
 */
void print_alias(char *name, param_t *params)
{
	unsigned int name_len = 0;
	list_t *ptr = params->alias_head;

	name_len = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, name_len - 1) == 0)
			_printf("%s=\'%s\'\n", ptr->str, ptr->val);
		ptr = ptr->next;
	}
	params->status = 0;
}

/**
 * print_all_aliases - Prints all aliases in the alias list.
 * @params: Parameter struct containing the alias list.
 *
 * Description: This function iterates through the alias list stored in the
 * parameter struct and prints the name and value of each alias to stdout.
 */
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}

/**
 * print_list_alias - Prints the name and value of each alias in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Description: This function recursively iterates through the linked list of
 * aliases and prints the name and value of each alias to stdout.
 */
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}

