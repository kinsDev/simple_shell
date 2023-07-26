#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/**
 * _alias - Implements the "alias" shell command.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function defines new aliases or prints existing aliases in the shell.
 * If called with no arguments, it prints all existing aliases.
 * If called with arguments, it assumes each argument is an alias name or definition,
 * and performs the appropriate action.
 */
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
