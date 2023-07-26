#include <stdlib.h>
#include "kkshell.h"

/**
 * move_left - Removes leading zeros from a binary string.
 * @a: Buffer containing the binary string.
 * @size: Size of the buffer.
 * @num: Number of digits in the binary number.
 *
 * Return: Pointer to the modified buffer.
 */
char *move_left(char *a, int size, int num)
{
	int i;
	char *ptr;
	for (i = 0, ptr = (a + size - num); i < num; i++, ptr++)
		*(a + i) = *ptr;
	*(a + num) = '\0';
	return (a);
}

/**
 * get_binary - Converts an unsigned int to a binary string.
 * @n: Integer to be converted.
 *
 * Return: Pointer to the binary string.
 */
char *get_binary(unsigned int n)
{
	char *ptr = NULL;
	unsigned int i, num = 0, size = 0;

	if (n == 0)
	{
		ptr = malloc(2);
		if (ptr)
		{
			ptr[0] = '0';
			ptr[1] = '\0';
		}
	return (ptr);
	}
	size = sizeof(int) * 8 + 1;
	ptr = malloc(size);
	if (ptr)
	{
	for (i = 0; i < size; i++)
        	ptr[i] = '0';
		ptr[size - 1] = '\0';

	i = size - 2;
	while (n != 0)
	{
		ptr[i] = n % 2 == 0 ? '0' : '1';
		num++;
		n = n / 2;
		i--;
	}
	num++;
	ptr = move_left(ptr, size, num);
	}
	return (ptr);
}

/**
 * get_char - Returns a copy of a single character.
 * @c: The character to be copied.
 *
 * Return: Pointer to the copied character.
 */
char *get_char(char c)
{
	char *ptr = NULL;

	ptr = malloc(2);
	if (ptr == NULL)
		return (NULL);

	ptr[0] = c;
	ptr[1] = '\0';
	return (ptr);
}
