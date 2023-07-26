#include <unistd.h>
#include <stdlib.h>
#include "kkshell.h"
#include "main.h"

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - Reallocate the line buffer with a new size.
 * @line: Pointer to the line buffer.
 * @oldSize: Current size of the line buffer.
 * @newSize: New size to reallocate.
 *
 * Return: Pointer to the reallocated buffer or NULL on failure.
 */
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
{
	char *newLine = NULL;
	unsigned int i;

	newLine = malloc(newSize);
	if (newLine)
	{
		for (i = 0; i < oldSize; i++)
			newLine[i] = (*line)[i];
		free(*line);
		*line = newLine;
	}
	return (newLine);
}
