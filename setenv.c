/**
 * _setenv - Sets the value of an environment variable.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function searches the environment list to find the environment variable name
 * and sets it to the corresponding value string. If the variable does not exist,
 * a new variable is added to the environment list with the specified name and value.
 */
void _setenv(param_t *params)
{
	char *env_name = NULL, *env_value = NULL;
	char *name = params->args[1], *value = params->args[2];
	list_t *env_node = params->env_head;

	if (params->tokCount != 3)
	{
		params->status = 0;
		return;
	}

	while (env_node)
	{
		if (_strcmp(name, env_node->str) == 0)
		{
			env_name = env_node->str;
			env_value = env_node->val;
			free(env_value);
			env_node->val = _strdup(value);
			if (!env_node->val)
			{
				write(STDERR_FILENO, "setenv malloc error\n", 18);
				exit(-1);
			}
			env_node->valLen = _strlen(value);
			params->status = 0;
			return;
		}
		env_node = env_node->next;
	}

	/* If the environment variable does not exist, add it to the environment list. */
	params->env_head = add_node(&(params->env_head), name, value);
	params->status = 0;
}

/**
 * _unsetenv - Removes an environment variable.
 * @params: Pointer to a param_t struct with the shell state and arguments.
 *
 * This function searches the environment list to find the environment variable name
 * and removes it if it exists.
 */
void _unsetenv(param_t *params)
{
	char *name = params->args[1];
	list_t *prev_node = NULL, *env_node = params->env_head;

	if (params->tokCount != 2)
	{
		params->status = 0;
		return;
	}

	while (env_node)
	{
		if (_strcmp(name, env_node->str) == 0)
		{
			if (env_node == params->env_head)
				params->env_head = env_node->next;
			else
				prev_node->next = env_node->next;

			free(env_node->str);
			free(env_node->val);
			free(env_node);
			params->status = 0;
			return;
		}

		prev_node = env_node;
		env_node = env_node->next;
	}

	params->status = 0;
}

