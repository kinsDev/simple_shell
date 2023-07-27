#include "lists.h"
#include "kkshell.h"
#include <stdlib.h>

/**
 * free_params - Frees the memory allocated for the param_t structure.
 * 
 * @params: Pointer to the param_t structure to free.
 *
 * This function frees the dynamically allocated memory used by the param_t
 * structure, including its members: the array of arguments, the environment
 * list, the alias list, the input buffer, and the nextCommand string.
 */
void free_params(param_t *params)
{
    /* Free the input buffer */
    if (params->buffer)
        free(params->buffer);

    /* Free the next command string */
    if (params->nextCommand)
        free(params->nextCommand);

    /* Free the environment list */
    free_list(params->env_head);

    /* Free the alias list */
    free_list(params->alias_head);

    /* Free each argument in the args array */
    for (unsigned int i = 0; params->args[i]; i++)
    {
        free(params->args[i]);
    }

    /* Free the args array itself */
    free(params->args);

    /* Free the param_t structure itself */
    free(params);
}

