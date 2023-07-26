#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: First string argument.
 * @s2: Second string argument.
 *
 * Return: Pointer to a new string with the concatenated result.
 *         NULL on failure or if s1 and s2 are NULL.
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	unsigned int i, j, len1, len2;

	/* Check if s1 is NULL, set to empty string if so */
	if (s1 == NULL)
		s1 = "";

	/* Check if s2 is NULL, set to empty string if so */
	if (s2 == NULL)
		s2 = "";

	/* Calculate the lengths of s1 and s2 */
	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	/* Allocate memory for the concatenated string, plus 1 for '\0' */
	result = malloc((len1 + len2 + 1) * sizeof(char));

	/* Check if memory allocation was successful */
	if (result == NULL)
		return (NULL);

	/* Copy characters from s1 to the result string */
	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	/* Copy characters from s2 to the result string */
	for (j = 0; j < len2; j++)
		result[i + j] = s2[j];

	/* Add the null-terminating character */
	result[i + j] = '\0';

	return (result);
}

/**
 * string_nconcat - Concatenates n bytes of two strings.
 * @s1: First string argument.
 * @s2: Second string argument.
 * @n: Number of bytes of s2 to concatenate.
 *
 * Return: Pointer to a new string with the concatenated result.
 *         NULL on failure or if s1 and s2 are NULL.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int i, j, len1, len2;

	/* Check if s1 is NULL, set to empty string if so */
	if (s1 == NULL)
		s1 = "";

	/* Check if s2 is NULL, set to empty string if so */
	if (s2 == NULL)
		s2 = "";

	/* Calculate the lengths of s1 and s2 */
	for (len1 = 0; s1[len1] != '\0'; len1++)
		;
	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	/* Limit n to the length of s2 */
	if (n > len2)
		n = len2;

	/* Allocate memory for the concatenated string, plus 1 for '\0' */
	result = malloc((len1 + n + 1) * sizeof(char));

	/* Check if memory allocation was successful */
	if (result == NULL)
		return (NULL);

	/* Copy characters from s1 to the result string */
	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	/* Copy n characters from s2 to the result string */
	for (j = 0; j < n; j++)
		result[i + j] = s2[j];

	/* Add the null-terminating character */
	result[i + j] = '\0';

	return (result);
}

/**
 * _strlen - Returns the length of a string.
 * @s: String.
 *
 * Return: Length of the string (excluding the null-terminating character).
 */
int _strlen(char *s)
{
	int length = 0;

	if (s == NULL)
		return (0);

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * _strdup - Copies a string to a newly allocated block of memory.
 * @str: String to be copied.
 *
 * Return: Pointer to the duplicated string, NULL if insufficient memory.
 */
char *_strdup(char *str)
{
	int len = 0;
	char *ptr = NULL;

	if (!str)
		return (NULL);

	/* Calculate the length of the string */
	while (*str)
	{
		len++;
		str++;
	}

	/* Allocate memory for the duplicated string */
	ptr = (char *)malloc(sizeof(char) * (len + 1));

	/* Check if memory allocation was successful */
	if (ptr)
	{
		/* Copy the string to the newly allocated memory */
		while (len >= 0)
			*(ptr + len--) = *(str--);
	}

	return (ptr);
}

/**
 * _strchr - Locates a character in a string.
 * @s: String to start looking.
 * @c: Value to find.
 *
 * Return: Pointer to the beginning of the memory area where the character is found.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}

	/* Check if the character is the null-terminating character */
	if (c == '\0')
		return (&s[i]);

	return (0);
}

