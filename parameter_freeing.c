#include "kkshell.h"
#include "main.h"
#include <stdlib.h>

/**
 * free_params - Frees the memory allocated for the param_t structure.
 *
 * @params: Pointer to the param_t structure to free.
 *
 * This function frees the dynamically allocated memory used by the param_t
 * structure, including its members: the input buffer, the array of arguments,
 * the environment list, and the alias list.
 */
void free_params(param_t *params)
{
    unsigned int i;

    /* Free the input buffer if it's not NULL */
    if (params->buffer)
        free(params->buffer);

    /* Free the nextCommand buffer if it's not NULL */
    if (params->nextCommand)
        free(params->nextCommand);

    /* Free the linked list of environment variables */
    free_list(params->env_head);

    /* Free the linked list of aliases */
    free_list(params->alias_head);

    /* Free each argument in the args array */
    for (i = 0; params->args[i]; i++)
        free(params->args[i]);

    /* Free the args array */
    free(params->args);

    /* Free the param_t structure itself */
    free(params);
}

