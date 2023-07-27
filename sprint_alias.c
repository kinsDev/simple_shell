#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/* Function to print the value of a specific alias if it exists */
void print_alias(char *name, param_t *params)
{
    unsigned int len = 0;
    list_t *ptr = params->alias_head;

    len = _strlen(name);
    while (ptr)
    {
        if (_strcmp_n(name, ptr->str, len - 1) == 0)
            _printf("%s=\'%s\'\n", ptr->str, ptr->val);
        ptr = ptr->next;
    }
    params->status = 0;
}

/* Function to print all aliases in the alias list */
void print_all_aliases(param_t *params)
{
    /* Call helper function to print the linked list of aliases */
    print_list_alias(params->alias_head);
    params->status = 0;
}

/* Helper function to print the name and value of each alias in a linked list */
void print_list_alias(list_t *head)
{
    if (head)
    {
        /* Recursively traverse the linked list to print aliases in reverse order */
        print_list_alias(head->next);
        if (head->str != NULL)
            _printf("%s=\'%s\'\n", head->str, head->val);
    }
}
