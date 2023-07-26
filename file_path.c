#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "kkshell.h"
#include "lists.h"

/**
 * get_file - Get the correct path to a command file
 * @params: Pointer to the parameters structure
 *
 * Return: A string containing the valid path to the command file,
 *         or NULL if the command is not found. The returned string
 *         needs to be freed by the caller.
 */
char *get_file(param_t *params)
{
	char *path = NULL;
	char *exePath = NULL, *exeArg = NULL, *tmp = NULL;
	char *state = NULL;

	/* Check if the command is in the current directory */
	if (access(params->args[0], F_OK | X_OK) == 0)
	{
		free(path);
		return (_strdup(params->args[0])); // Return the absolute path to the command
	}

	/* If the command is not in the current directory, check for permissions */
	if (errno == EACCES)
	{
		params->status = 126; // Permission denied error code
		write_error(params, "Permission denied\n");
		return (NULL);
	}

	/* Get the value of the PATH environment variable */
	path = _getenv("PATH", params);
	if (!path)
	{
		write_error(params, "not found\n");
		return (NULL);
	}

	/* Tokenize the PATH and look for the command in each directory */
	exePath = _strtok(path, ":", &state);
	while (exePath)
	{
		tmp = exeArg;
		exeArg = str_concat(exePath, "/");
		free(tmp);
		tmp = exeArg;
		exeArg = str_concat(exeArg, params->args[0]);
		free(tmp);

		/* Check if the command is found in the current directory */
		if (access(exeArg, F_OK) == 0)
		{
			free(path);
			free(exePath);
			return (exeArg); // Return the absolute path to the command
		}

		free(exePath);
		exePath = _strtok(path, ":", &state); // Move to the next directory in PATH
	}

	/* If the command is not found in any directory, return an error */
	params->status = 127; // Command not found error code
	write_error(params, "not found\n");
	free(path);
	free(exePath);
	free(exeArg);
	return (NULL);
}

