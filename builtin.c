#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
#include "lists.h"
#include "kkshell.h"

/**
 * get_builtin - Get the built-in function.
 * @params: Pointer to the param_t struct containing command parameters.
 *
 * Description: This function searches for a built-in function based on the
 * first argument in the param_t struct. It returns a function pointer to the
 * corresponding built-in function if found, or NULL if not found.
 *
 * Return: Function pointer to the built-in function. NULL if not found.
 */
void (*get_builtin(param_t *params))(param_t *)
{
    builtin_op builtins[] = {
        {"exit", my_exit},
        {"clear", clear_screen},
        {"env", print_env},
        {"setenv", set_env},
        {"cd", change_directory},
        {"unsetenv", unset_env},
        {"alias", handle_alias},
        {NULL, NULL},
    };
    builtin_op *builtin = builtins;

    while (builtin->name)
    {
        if (!_strcmp(params->args[0], builtin->name))
            return (builtin->func);
        builtin++;
    }
    return (NULL);
}

