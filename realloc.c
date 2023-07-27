#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocates a memory block using malloc
 * @ptr: old block
 * @old_size: size of the old block
 * @new_size: size of the new block
 *
 * Return: pointer to new block
 */
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	/* If ptr is NULL, treat it as equivalent to malloc(new_size). */
	if (!ptr)
	{
		free(ptr);
		return (malloc(sizeof(*ptr) * new_size));
	}

	/* If new_size is 0, free the old block and return NULL. */
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* If the new size is the same as the old size, return the original pointer. */
	if (new_size == old_size)
		return (ptr);

	char **newPtr = NULL;
	unsigned int num, i;

	/* Determine the number of elements to copy from the old block to the new block. */
	num = old_size < new_size ? old_size : new_size;

	/* Allocate memory for the new pointer. */
	newPtr = malloc(sizeof(*newPtr) * new_size);

	if (newPtr)
	{
		/* Initialize all pointers in the new block to NULL. */
		for (i = 0; i < new_size; i++)
			newPtr[i] = NULL;

		/* Copy elements from the old block to the new block. */
		for (i = 0; i < num; i++)
			newPtr[i] = ptr[i];

		/* Free the old block. */
		free(ptr);
	}

	return (newPtr);
}

