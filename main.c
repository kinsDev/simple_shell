#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "kkshell.h"
#include "main.h" /* for _printf */

#define BUFFER_SIZE 4096

/* Function prototype */
param_t *init_param(char **argv, char **env);

/**
 * main - entry to the program
 * @argc: argument count
 * @argv: argument list
 * @env:  environment variables list
 *
 * Return: 0 on success
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
    param_t *params = NULL;
    int condition = -2, status;
    unsigned int i;
    char *state = NULL;
    size_t size = BUFFER_SIZE;

    /* Initialize shell parameters */
    params = init_param(argv, env);
    if (!params)
        exit(-1);
    signal(SIGINT, sigint_handler);

    while (1)
    {
        /* Handle exit condition */
        if (condition == -1)
        {
            status = params->status;
            _printf("$ \n");
            free_params(params);
            return (status);
        }

        /* Clear the buffer for new input */
        for (i = 0; i < BUFFER_SIZE; i++)
            (params->buffer)[i] = 0;

        params->tokCount = 0;

        /* Display prompt if running in an interactive terminal */
        if (isatty(STDIN_FILENO))
            _printf("$: ");

        /* Get input from the user */
        condition = getline(&params->buffer, &size, stdin);
        params->lineCount++;

        if (condition == -1 && _strlen(params->buffer) == 0)
        {
            /* Handle exit condition if Ctrl+D is pressed */
            status = params->status;
            free_params(params);
            return (status);
        }

        state = NULL;
        params->nextCommand = _strtok(params->buffer, ";\n", &state);

        /* Process multiple commands separated by ';' or '\n' */
        while (params->nextCommand)
        {
            /* Process the command and get the number of tokens */
            params->tokCount = process_string(params);

            if (params->tokCount == 0)
                break;

            /* Execute the command */
            run_command(params);

            /* Clean up memory and prepare for the next command */
            for (i = 0; i < params->argsCap; i++)
            {
                free(params->args[i]);
                params->args[i] = NULL;
            }
            params->tokCount = 0;
            free(params->nextCommand);
            params->nextCommand = _strtok(params->buffer, ";\n", &state);
        }
    }
}

/**
 * init_param - initialize params
 * @argv: command line argument
 * @env: environment variables
 * Return: param on success
 */
param_t *init_param(char **argv, char **env)
{
    unsigned int i;
    char *eqs = NULL;
    param_t *params = malloc(sizeof(*params));

    if (!params)
        return (NULL);

    params->argsCap = 10;
    params->lineCount = 0;
    params->tokCount = 0;
    params->status = 0;
    params->argv = argv;
    params->nextCommand = NULL;

    /* Allocate memory for the buffer */
    params->buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (!(params->buffer))
    {
        free(params);
        exit(-1);
    }

    for (i = 0; i < BUFFER_SIZE; i++)
        params->buffer[i] = 0;

    /* Allocate memory for the argument list */
    params->args = malloc(sizeof(char *) * params->argsCap);
    if (!(params->args))
    {
        free(params->buffer);
        free(params);
        exit(-1);
    }

    for (i = 0; i < params->argsCap; i++)
        params->args[i] = NULL;

    params->env_head = NULL;

    /* Create a linked list of environment variables */
    for (i = 0; env[i]; i++)
    {
        eqs = _strchr(env[i], '=');
        *eqs = '\0';
        params->env_head = add_node(&(params->env_head), env[i], eqs + 1);
        if (!(params->env_head))
        {
            free(params->buffer);
            free(params->args);
            free_list(params->env_head);
            free(params);
            exit(-1);
        }
    }

    params->alias_head = NULL;

    return (params);
}

