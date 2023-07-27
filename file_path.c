#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "kkshell.h"
#include "lists.h"
#include <unistd.h>

/**
 * get_file - get correct path to a command file
 * @params: parameters
 *
 * Return: string of valid path to command file, NULL if not found
 * The string needs to be freed
 */
char *get_file(param_t *params)
{
	/* Variables */
	char *path = NULL;     /* Holds the PATH environment variable */
	char *exePath = NULL;  /* Holds each individual path from the PATH variable */
	char *exeArg = NULL;   /* Holds the concatenated path and command */
	char *tmp = NULL;      /* Temporary variable for string concatenation */
	char *state = NULL;    /* State for strtok_r function */

	/* Check if the command is in the current directory */
	if (access(params->args[0], F_OK | X_OK) == 0)
	{
		/* No need to search, command is in the current directory */
		free(path);
		return (_strdup(params->args[0])); /* Return a duplicated string */
	}

	/* Check if the user has permission to execute the command */
	if (errno == EACCES)
	{
		params->status = 126;
		write_error(params, "Permission denied\n");
		return (NULL);
	}

	/* Get the PATH environment variable */
	path = _getenv("PATH", params);
	if (!path)
	{
		write_error(params, "not found\n");
		return (NULL);
	}

	/* Loop through each path in the PATH variable */
	exePath = _strtok(path, ":", &state);
	while (exePath)
	{
		/* Concatenate the path and command */
		tmp = exeArg;
		exeArg = str_concat(exePath, "/");
		free(tmp);
		tmp = exeArg;
		exeArg = str_concat(exeArg, params->args[0]);
		free(tmp);

		/* Check if the command exists in the current path */
		if (access(exeArg, F_OK) == 0)
		{
			free(path);
			free(exePath);
			return (exeArg); /* Return the valid path to the command */
		}

		free(exePath);
		exePath = _strtok(path, ":", &state); /* Get the next path */
	}

	/* Command not found in any of the paths */
	params->status = 127;
	write_error(params, "not found\n");

	/* Clean up and return NULL */
	free(path);
	free(exePath);
	free(exeArg);
	return (NULL);
}

