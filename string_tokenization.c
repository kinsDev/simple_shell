#include <stdlib.h>
#include "kkshell.h"
#include "main.h"

/**
 * is_delimiter - Check if a character is one of the delimiters.
 * @c: Character to check.
 * @delim: Delimiters.
 *
 * Return: 1 if it is a delimiter, 0 otherwise.
 */
int is_delimiter(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - Custom implementation of strtok_r.
 * @str: String to be parsed.
 * @delim: Delimiters for tokens.
 * @save_ptr: State to store the current position in the string.
 *
 * Return: Next token found in the string, NULL if not found.
 */
char *_strtok(char *str, char *delim, char **save_ptr)
{
	char *ptr, *modifier, *end;
	int quote_found = 0;

	if (*save_ptr)
		ptr = *save_ptr;
	else
		ptr = str;

	end = ptr;
	while (*end)
		end++;

	while (*ptr && is_delimiter(*ptr, delim))
		ptr++;

	modifier = ptr;

	if (*ptr == '\0')
	{
		return (NULL);
	}

	if (*ptr == '\'')
	{
		ptr++;
		modifier = _strchr(ptr, '\'');
		if (!modifier)
		{
			_printf("No matching quote found!\n");
			exit(-1);
		}
		*modifier = '\0';
		*save_ptr = modifier + 1;
		return (_strdup(ptr));
	}

	while (*modifier)
	{
		if (*modifier == '\'')
			quote_found = 1;

		if (is_delimiter(*modifier, delim) && quote_found == 0)
			break;

		modifier++;
	}

	if (*modifier == '\0')
		*save_ptr = modifier;
	else
		*save_ptr = modifier + 1;

	*modifier = '\0';
	return (_strdup(ptr));
}

