#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * process_string - Tokenize and process the next command into string tokens
 * @params: Pointer to the shell parameters
 *
 * Return: Number of tokens processed
 */
int process_string(param_t *params)
{
	char *token = NULL, *state = NULL;
	char *alias = NULL, *state_2 = NULL, *val;
	list_t *alias_node;

	token = _strtok(params->nextCommand, " \n\t", &state);
	if (!token)
	{
		params->tokCount = 0;
		return (0);
	}

	alias_node = get_node(params->alias_head, token);
	if (alias_node != NULL)
	{
		free(token);
		token = NULL;

		alias = _strdup(alias_node->val);
		if (!alias)
		{
			write_error(params, "alias expansion malloc error\n");
			free_params(params);
			exit(-1);
		}

		val = _strtok(alias, " \n\t", &state_2);
		params->args[params->tokCount++] = val;

		while (val)
		{
			val = _strtok(NULL, " ", &state_2);
			params->args[params->tokCount++] = val;
		}
		free(alias);
	}
	else
	{
		params->args[params->tokCount++] = token;
	}

	token = _strtok(params->nextCommand, " \n\t", &state);
	params->args[params->tokCount++] = token;

	while (token)
	{
		token = _strtok(NULL, " \n\t", &state);
		params->args[params->tokCount++] = token;

		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args,
						params->argsCap - 10,
						params->argsCap);
			if (!(params->args))
			{
				write_error(params, "realloc error\n");
				free_params(params);
				exit(-1);
			}
		}
	}

	return (params->tokCount - 1);
}

