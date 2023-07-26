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

/**
 * _getline - Reads a line of characters from stdin.
 * @params: Pointer to the parameter structure.
 *
 * Return: Number of characters read, -1 on EOF or error.
 */
int _getline(param_t *params)
{
	char *line = NULL;
	static unsigned int bufferSize = BUFFER_SIZE;
	char *writeHead = line;
	unsigned int len;

	line = malloc(BUFFER_SIZE);
	do {
		len = read(0, writeHead, BUFFER_SIZE);
		if (len == 0)
			break;
		writeHead += len;
		if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = rlLine(&line, bufferSize, bufferSize * 2);
			bufferSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->input_line);
	params->input_line = line;
	if (len == 0)
		return (-1);
	return (_strlen(params->input_line));
}

