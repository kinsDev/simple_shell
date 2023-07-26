#include <stdlib.h>
#include <unistd.h>
#include "kkshell.h"
#include <stdio.h>

/**
 * process_string - Process the next command into string tokens.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function processes the next command from the input buffer
 * into individual string tokens. It checks for aliases and expands
 * them accordingly. The tokens are stored in the args array of the
 * parameter struct.
 *
 * Return: The number of tokens processed.
 */
int process_string(param_t *params)
{
	char *token = NULL, *state = NULL;
	char *alias = NULL, *state_2 = NULL, *val;
	list_t *node;

	/* Get the first token from the nextCommand using strtok. */
	token = _strtok(params->nextCommand, " \n\t", &state);
	if (!token)
	{
		params->tokCount = 0;
		return (0);
	}

	/* Check if the token matches any existing alias. */
	node = get_node(params->alias_head, token);
	if (node != NULL)
	{
		free(token);
		token = NULL;
		alias = _strdup(node->val);
		if (!alias)
		{
			write(STDERR_FILENO,
			      "alias expansion malloc error\n", 18);
			free_params(params);
			exit(-1);
		}

		/* Tokenize the alias value and store each token in args array. */
		val = _strtok(alias, " \n\t", &state_2);
		(params->args)[(params->tokCount)++] = val;
		while (val)
		{
			val = _strtok(alias, " ", &state_2);
			(params->args)[(params->tokCount)++] = val;
		}
		free(alias);
	}
	else
	{
		(params->args)[(params->tokCount)++] = token;
	}

	/* Tokenize the remaining string and store in args array. */
	token = _strtok(params->nextCommand, " \n\t", &state);
	params->args[params->tokCount++] = token;
	while (token)
	{
		token = _strtok(params->nextCommand, " \n\t", &state);
		(params->args)[(params->tokCount)++] = token;

		/* Check if args array needs resizing and perform reallocation if necessary. */
		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args,
						params->argsCap - 10,
						params->argsCap);
			if (!(params->args))
			{
				write(STDERR_FILENO, "realloc error\n", 14);
				free_params(params);
				exit(-1);
			}
		}
	}
	return (params->tokCount - 1);
}

