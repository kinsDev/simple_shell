#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "kkshell.h"
#include "lists.h"
#include "main.h"

/**
 * run_command - Execute a command by searching for it in the PATH
 * and executing it.
 * @params: Pointer to the param_t structure containing shell variables.
 */
void run_command(param_t *params)
{
	/* Function pointers to built-in commands and external executable */
	void (*builtin_cmd)(param_t *);
	char *executable_file = NULL;
	pid_t pid;

	/* Check if the command is a built-in command */
	builtin_cmd = get_builtin(params);
	if (builtin_cmd)
	{
		builtin_cmd(params);
		return;
	}

	/* Find the full path of the executable file in the PATH directories */
	executable_file = get_file(params);
	if (!executable_file)
	{
		/* Error: Command not found or invalid */
		return;
	}

	/* Fork a new process to execute the command */
	pid = fork();
	if (pid < 0)
	{
		/* Error: Forking failed */
		free_params(params);
		exit(98);
	}
	else if (pid == 0)
	{
		/* Child process: Execute the command */
		execve(executable_file, params->args, NULL);
	}
	else
	{
		/* Parent process: Wait for the child process to complete */
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(executable_file);
	}
}

