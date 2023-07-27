#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "kkshell.h"
#include "main.h"
#include "lists.h"

/**
 * run_command - Searches path directories for the command and executes it.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function attempts to execute the command provided in the params->args array.
 * If the command is a built-in command, it is executed directly.
 * If the command is an external program, this function searches the path directories
 * for the executable file and then forks a child process to execute it.
 */
void run_command(param_t *params)
{
    char *exeFile = NULL; // Stores the path to the executable file.
    pid_t pid; // Stores the process ID of the child process.

    // Check if the command is a built-in command and execute it if it is.
    void (*builtin_func)(param_t *);
    builtin_func = get_builtin(params);
    if (builtin_func)
    {
        builtin_func(params);
        return;
    }

    // Search for the executable file in the path directories.
    exeFile = get_file(params);
    if (!exeFile)
    {
        // If the executable file is not found, return.
        return;
    }

    // Fork a child process to execute the external command.
    pid = fork();
    if (pid < 0)
    {
        // Fork failed. Free resources and exit the child process.
        free_params(params);
        exit(98);
    }
    else if (pid == 0)
    {
        // Child process: execute the external command using execve.
        execve(exeFile, params->args, NULL);

        // If execve returns, it means the command execution failed.
        // Print an error message and exit the child process.
        _printf("kkshell: command not found: %s\n", params->args[0]);
        exit(127);
    }
    else
    {
        // Parent process: wait for the child process to complete.
        wait(&params->status);
        params->status = WEXITSTATUS(params->status);
        free(exeFile);
    }
}

