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

	/* Handle case when input string is NULL */
	if (str == NULL)
	{
		str = "(null)";
	}

	/* Calculate the length of the string */
	for (length = 0; str[length] != '\0'; length++)
		;

	head = 0;
	tail = length - 1;

	/* Swap characters from the beginning and end of the string */
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
 * get_reversed_copy - Returns a reversed copy of a string.
 * @s: String to be reversed.
 * Return: Pointer to the reversed string.
 */
char *get_reversed_copy(char *s)
{
	char *reversed_str = NULL;

	/* Get a copy of the input string */
	reversed_str = get_string(s);

	/* Check if allocation was successful */
	if (!reversed_str)
	{
		return (NULL);
	}

	/* Reverse the copied string */
	if (s)
	{
		reverse_string(reversed_str);
	}

	return (reversed_str);
}

/**
 * rot13_encryption - Performs ROT13 encryption on a string.
 * @s: String to be encrypted.
 *
 * Return: Pointer to the encrypted string.
 */
char *rot13_encryption(char *s)
{
	char *encrypted_str;
	int i;
	char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
				'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
				'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
				'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
				'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char rot13_chars[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
				'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
				'j', 'k', 'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
				'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E',
				'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};

	/* Get a copy of the input string */
	encrypted_str = get_string(s);

	if (!encrypted_str)
	{
		return (NULL);
	}

	/* Perform ROT13 encryption on the copied string */
	for (i = 0; encrypted_str[i] != '\0'; i++)
	{
		int index;
		for (index = 0; index < 52; index++)
		{
			if (encrypted_str[i] == characters[index])
			{
				encrypted_str[i] = rot13_chars[index];
				break;
			}
		}
	}

	return (encrypted_str);
}

/**
 * get_rot13_encrypted_copy - Get ROT13 encrypted copy.
 * @s: String.
 * Return: Pointer to the encrypted string.
 */
char *get_rot13_encrypted_copy(char *s)
{
	char *encrypted_str = NULL;

	/* Get a copy of the input string */
	encrypted_str = get_string(s);

	if (!encrypted_str)
		return (NULL);

	/* Perform ROT13 encryption on the copied string */
	if (s)
	{
		rot13_encryption(encrypted_str);
	}

	return (encrypted_str);
}

