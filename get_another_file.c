#include "kkshell.h"
#include "main.h"
#include <stdlib.h>

/**
 * reverse_string - Reverses the order of characters in a string.
 * @str: A pointer to a null-terminated string to be reversed.
 */
void reverse_string(char *str)
{
	int head, tail;
	int length;
	char tmp;

	if (str == NULL)
	{
		str = "(null)";
	}

	/* Calculate the length of the string */
	for (length = 0; str[length] != '\0'; length++)
		;

	head = 0;
	tail = length - 1;

	/* Swap characters to reverse the string */
	while (head < tail)
	{
		tmp = *(str + head);
		*(str + head) = *(str + tail);
		*(str + tail) = tmp;
		head++;
		tail--;
	}
}

/**
 * get_reversed_string - Returns a reversed copy of a string.
 * @str: String to be reversed.
 * Return: Reversed string.
 */
char *get_reversed_string(char *str)
{
	char *ptr = NULL;

	/* Get a copy of the input string */
	ptr = get_string(str);
	if (!ptr)
	{
		return (NULL);
	}
	/* Reverse the string */
	if (str)
	{
		reverse_string(ptr);
	}
	return (ptr);
}

/**
 * rot13_encryption - Performs ROT13 encryption on a string.
 * @str: String to be encrypted.
 *
 * Return: Pointer to the encrypted string.
 */
char *rot13_encryption(char *str)
{
	char *ptr;
	int i;
	char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
	char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13_lowercase[] = "nopqrstuvwxyzabcdefghijklm";
	char rot13_uppercase[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	/* Loop through the string and perform ROT13 encryption */
	for (ptr = str; *ptr != '\0'; ptr++)
	{
		for (i = 0; i < 26; i++)
		{
			if (*ptr == lowercase[i])
			{
				*ptr = rot13_lowercase[i];
				break;
			}
			else if (*ptr == uppercase[i])
			{
				*ptr = rot13_uppercase[i];
				break;
			}
		}
	}
	return (str);
}

/**
 * get_rot13_encryption - Get ROT13 encryption.
 * @str: String to be encrypted.
 * Return: Pointer to the encrypted string.
 */
char *get_rot13_encryption(char *str)
{
	char *ptr = NULL;

	/* Get a copy of the input string */
	ptr = get_string(str);
	if (!ptr)
		return (NULL);

	/* Perform ROT13 encryption on the string */
	if (str)
	{
		rot13_encryption(ptr);
	}
	return (ptr);
}

