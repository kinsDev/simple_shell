#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/**
 * _setenv - Searches the environment list to find the
 * environment variable name, and sets it to the corresponding
 * value string.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 */
void _setenv(param_t *params)
{
    char *env_name = NULL;
    char *env_value = NULL;
    char *name = params->args[1];
    char *value = params->args[2];
    list_t *current_env = params->env_head;

    if (params->tokCount != 3)
    {
        params->status = 0;
        return;
    }

    while (current_env)
    {
        if (_strcmp(name, current_env->str) == 0) /* Environment variable exists */
        {
            env_name = current_env->val;
            free(env_name);
            current_env->val = _strdup(value);
            if (!current_env->val)
            {
                write(STDERR_FILENO, "setenv malloc error\n", 18);
                exit(-1);
            }
            current_env->valLen = _strlen(value);
            params->status = 0;
            return;
        }
        current_env = current_env->next;
    }

    /* Environment variable does not exist */
    params->env_head = add_node(&(params->env_head), name, value);
    params->status = 0;
}

/**
 * _unsetenv - Searches the environment list to find the
 * environment variable name and removes it.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 */
void _unsetenv(param_t *params)
{
    char *name = params->args[1];
    list_t *prev_env = NULL;
    list_t *current_env = params->env_head;

    if (params->tokCount != 2)
    {
        params->status = 0;
        return;
    }

    while (current_env)
    {
        if (_strcmp(name, current_env->str) == 0) /* Environment variable exists */
        {
            if (current_env == params->env_head)
                params->env_head = current_env->next;
            else
                prev_env->next = current_env->next;

            free(current_env->str);
            free(current_env->val);
            free(current_env);
            params->status = 0;
            return;
        }
        prev_env = current_env;
        current_env = current_env->next;
    }

    params->status = 0;
}

