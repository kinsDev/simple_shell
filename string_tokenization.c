#include <stdlib.h>
#include "kkshell.h"
#include "main.h"

/**
 * is_delimiter - Check if a character is one of the delimiters.
 * @c: Character to check.
 * @delimiters: Delimiter characters.
 *
 * Return: 1 if it is a delimiter, 0 otherwise.
 */
int is_delimiter(char c, char *delimiters)
{
	while (*delimiters)
	{
		if (c == *delimiters)
			return 1;
		delimiters++;
	}
	return 0;
}

/**
 * _strtok - A function similar to strtok_r.
 * @str: String to be tokenized.
 * @delimiters: Delimiters used for tokenization.
 * @savePtr: State to keep track of the current position in the string.
 *
 * Return: Next token found in the string, NULL if not found.
 */
char *_strtok(char *str, char *delimiters, char **savePtr)
{
	char *ptr, *modifier, *end;
	int quoteFound = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && is_delimiter(*ptr, delimiters))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return NULL;
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
		*savePtr = modifier + 1;
		return _strdup(ptr);
	}
	while (*modifier)
	{
		if (*modifier == '\'')
			quoteFound = 1;
		if (is_delimiter(*modifier, delimiters) && quoteFound == 0)
			break;
		modifier++;
	}
	if (*modifier == '\0')
		*savePtr = modifier;
	else
		*savePtr = modifier + 1;
	*modifier = '\0';
	return _strdup(ptr);
}

