#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - Reallocates a memory block using malloc.
 * @ptr: Pointer to the old block.
 * @old_size: Size of the old block.
 * @new_size: Size of the new block.
 *
 * Return: Pointer to the new block.
 */
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newPtr = NULL;
	unsigned int min_size, i;

	if (!ptr)
	{
		free(ptr);
		return (malloc(sizeof(*ptr) * new_size));
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	min_size = old_size < new_size ? old_size : new_size;
	newPtr = malloc(sizeof(*newPtr) * new_size);

	if (newPtr)
	{
		for (i = 0; i < new_size; i++)
			newPtr[i] = NULL;

		for (i = 0; i < min_size; i++)
			newPtr[i] = ptr[i];

		free(ptr);
	}

	return (newPtr);
}

