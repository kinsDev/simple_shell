#include "lists.h"
#include "kkshell.h"
#include <stdlib.h>

/**
 * free_params - Frees the memory allocated for the param_t structure.
 * 
 * @params: pointer to the param_t structure to free
 *
 * This function frees the dynamically allocated memory used by the param_t
 * structure, including its members: the array of arguments, the environment
 * list, and the input buffer.
 */

void free_params(param_t *params)
{
	/* Free the input buffer if it was allocated */
	if (params->buffer)
		free(params->buffer);

	/* Free the nextCommand string if it was allocated */
	if (params->nextCommand)
		free(params->nextCommand);

	/* Free the environment list */
	free_list(params->env_head);

	/* Free the alias list */
	free_list(params->alias_head);

	/* Free each argument in the arguments array and then free the array itself */
	for (unsigned int i = 0; params->args[i]; i++) {
		free(params->args[i]);
	}
	free(params->args);

	/* Free the param_t structure itself */
	free(params);
}

