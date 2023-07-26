#include <stdlib.h>
#include "main.h"
#include "lists.h"

/**
 * print_all_aliases - Prints all existing aliases.
 * @params: Pointer to a param_t struct with the shell state.
 *
 * This function prints all the existing aliases in the shell.
 * It traverses the alias list and prints each alias name and its value.
 */
void print_all_aliases(param_t *params)
{
    list_t *h = params->alias_head;

    while (h)
    {
        _printf("%s='%s'\n", h->str, h->val);
        h = h->next;
    }
}

/**
 * free_alias_list - Frees the alias list.
 * @head: Pointer to the head of the alias list.
 *
 * This function frees the memory allocated for the alias list.
 * It iterates through the list and frees each node.
 */
void free_alias_list(list_t *head)
{
    list_t *current, *next;

    current = head;
    while (current)
    {
        next = current->next;
        free(current->str);
        free(current->val);
        free(current);
        current = next;
    }
}

void _alias(param_t *params)
{
    unsigned int i;

    if (params->tokCount == 1)
    {
        /* If called with no arguments, print all existing aliases. */
        print_all_aliases(params);
        return;
    }

    for (i = 1; i < params->tokCount; i++)
    {
        if (_strchr(params->args[i], '='))
            set_alias(params->args[i], params);
        else
            print_alias(params->args[i], params);
    }
}

void set_alias(char *name, param_t *params)
{
    char *val, *tmp = NULL;
    unsigned int i = 0, j = 1;

    /* Find the location of the '=' character to separate the alias name and value. */
    while (name[i] && name[i] != '=')
        i++;

    if (name[i + 1] == '\'')
    {
        /* If the alias value is enclosed in single quotes. */
        if (_strchr(&name[i + 2], '\''))
        {
            tmp = _strchr(&name[i + 2], '\'');
            *tmp = '\0';
            val = _strdup(&name[i + 2]);

            /* Check if there are additional aliases defined in the value. */
            if (tmp[1] != '\0')
            {
                while (tmp[j] && (tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n'))
                    j++;
                if (tmp[j] != '\0')
                    set_alias(&tmp[j], params);
            }
        }
        else
        {
            /* Invalid alias format. Print usage message and return. */
            _printf("Usage: alias name='value' [...]\n");
            return;
        }
    }
    else
    {
        /* If the alias value is not enclosed in single quotes. */
        val = _strdup(&name[i + 1]);
    }

    name[i] = '\0'; /* Set '=' to terminator to separate name and value. */
    make_alias(name, val, params);
}

void make_alias(char *name, char *val, param_t *params)
{
    list_t *h = params->alias_head;

    while (h)
    {
        if (!_strcmp(name, h->str))
        {
            /* If the alias already exists, update its value. */
            free(h->val);
            h->val = val;
            h->valLen = _strlen(val);
            params->status = 0;
            return;
        }
        h = h->next;
    }

    /* If the alias doesn't exist, add it to the alias list. */
    params->alias_head = add_node(&(params->alias_head), name, val);
    free(val);
    params->status = 0;
}

