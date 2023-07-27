#include <stdlib.h>
#include "kkshell.h"
#include "main.h"
#include <unistd.h>

/**
 * _cd - change current working directory
 * @params: shell parameters
 *
 * Return: void
 */
void _cd(param_t *params)
{
	char *target = NULL, cwd[1024];
	char **tmpArgs = NULL, **originArgs = NULL;
	int i;

	/* Check if no arguments are provided, then change to HOME directory */
	if (params->tokCount == 1)
	{
		target = _getenv("HOME", params);
		if (!target)
		{
			params->status = 0;
			return;
		}
	}
	/* Check for "-" option, change to OLDPWD and print current directory */
	else if (params->args[1][0] == '-')
	{
		if (!_strcmp(params->args[1], "-"))
		{
			target = _getenv("OLDPWD", params);
			if (!target)
			{
				params->status = 0;
				target = _getenv("PWD", params);
				_printf("%s\n", target);
				free(target);
				return;
			}
			_printf("%s\n", target);
		}
		/* Invalid option provided */
		else
		{
			params->status = 2;
			_printf("%s: %d: cd: Illegal option %c%c\n",
				params->argv[0], params->lineCount,
				'-', params->args[1][1]);
			return;
		}
	}
	/* Change to the specified directory */
	else
	{
		target = _strdup(params->args[1]);
		if (!target)
		{
			write(STDERR_FILENO, "cd target malloc error\n", 23);
			exit(-1);
		}
	}

	/* Change the current working directory */
	i = chdir(target);
	if (i)
	{
		write_error(params, "can't cd to ");
		write(STDERR_FILENO, target, _strlen(target));
		write(STDERR_FILENO, "\n", 1);
		params->status = 0;
		free(target);
		return;
	}
	free(target);

	/* Save the current PWD to OLDPWD */
	tmpArgs = malloc(sizeof(char *) * 3);
	if (!tmpArgs)
		exit(-1);
	originArgs = params->args;
	params->args = tmpArgs;
	params->tokCount = 3;

	/* set OLDPWD to the current PWD */
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	if (!tmpArgs[0] || !tmpArgs[1])
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 23);
		free_params(params);
		exit(-1);
	}
	tmpArgs[2] = _getenv("PWD", params);
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(tmpArgs[i]);

	/* Set PWD to the target working directory */
	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("PWD");
	tmpArgs[2] = _strdup(getcwd(cwd, 1024));
	if (!tmpArgs[0] || !tmpArgs[1] || !tmpArgs[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 23);
		free_params(params);
		exit(-1);
	}
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(tmpArgs[i]);
	free(tmpArgs);

	/* Reset params */
	params->args = originArgs;
}

