#include "main.h"
#include <stdlib.h>

/**
 * rev_string - Reverses the order of characters in a string.
 * @s: A pointer to a null-terminated string to be reversed.
 */
void rev_string(char *s)
{
	int head, tail;
	int len;
	char tmp;

	if (s == NULL)
	{
		s = "(null)";
	}

	/* Find the length of the string */
	for (len = 0; s[len] != '\0'; len++)
		;

	head = 0;
	tail = len - 1;

	/* Swap characters from head and tail until the middle of the string is reached */
	while (head < tail)
	{
		tmp = *(s + head);
		*(s + head) = *(s + tail);
		*(s + tail) = tmp;
		head++;
		tail--;
	}
}

/**
 * get_rev - Returns a reversed copy of a string
 * @s: String to be reversed
 * Return: Reversed string or NULL if memory allocation fails
 */
char *get_rev(char *s)
{
	char *ptr = NULL;

	/* Get a copy of the original string */
	ptr = get_string(s);
	if (!ptr)
	{
		return (NULL);
	}

	if (s)
	{
		/* Reverse the copy */
		rev_string(ptr);
	}

	return (ptr);
}

/**
 * rot13 - Performs rot13 encryption on a string
 * @s: String to be encrypted
 *
 * Return: Pointer to the encrypted string
 */
char *rot13(char *s)
{
	char *ptr;
	int i;
	char c[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char r[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	/* Loop through the string */
	for (ptr = s; *ptr != '\0'; ptr++)
	{
		/* Check if the character is a letter and perform rot13 encryption */
		for (i = 0; i < 52; i++)
		{
			if (*ptr == c[i])
			{
				*ptr = r[i];
				break;
			}
		}
	}

	return (s);
}

/**
 * get_rot13 - Get rot13 encryption of a string
 * @s: String to be encrypted
 * Return: Pointer to the encrypted string or NULL if memory allocation fails
 */
char *get_rot13(char *s)
{
	char *ptr = NULL;

	/* Get a copy of the original string */
	ptr = get_string(s);
	if (!ptr)
		return (NULL);

	if (s)
	{
		/* Encrypt the copy using rot13 */
		rot13(ptr);
	}

	return (ptr);
}

