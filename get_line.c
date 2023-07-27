#include <unistd.h>
#include <stdlib.h>
#include "kkshell.h"
#include "main.h"

#define INITIAL_BUFFER_SIZE 4096
#define READ_CHUNK_SIZE 1024

/**
 * rlLine - Reallocate the line buffer to accommodate a larger size.
 * @line: Pointer to the buffer to be reallocated.
 * @oldSize: The current size of the buffer.
 * @newSize: The new desired size of the buffer.
 *
 * Return: A pointer to the new allocated buffer.
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
	return newLine;
}

/**
 * _getline - Reads a line of characters from stdin.
 * @params: Pointer to the parameter struct containing the shell state.
 *
 * This function reads a line of characters from the standard input (stdin).
 * It dynamically allocates memory for the buffer and reallocates it as needed
 * to accommodate the entire line. The buffer is stored in the params->buffer
 * variable, which should be freed by the caller after use.
 *
 * Return: The number of characters read (excluding the '\0' terminator), or -1
 *         if the end of the input is reached (EOF is encountered).
 */
int _getline(param_t *params)
{
	char *line = NULL;
	static unsigned int bufSize = INITIAL_BUFFER_SIZE;
	char *writeHead = line;
	unsigned int len;

	line = malloc(INITIAL_BUFFER_SIZE);
	do {
		len = read(0, writeHead, READ_CHUNK_SIZE);
		if (len == 0)
			break;
		writeHead += len;
		if (writeHead >= (line + bufSize - 1 - READ_CHUNK_SIZE))
		{
			line = rlLine(&line, bufSize, bufSize * 2);
			bufSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->buffer);
	params->buffer = line;
	if (len == 0)
		return -1;
	return _strlen(params->buffer);
}

