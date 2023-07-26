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

/**
 * get_string - Returns a duplicated string.
 * @s: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string or NULL if @s is NULL.
 */
char *get_string(char *s)
{
	char *ptr = NULL;
	int i, j;

	if (s == NULL)
	{
		ptr = malloc(7);
		if (ptr == NULL)
			return (NULL);

		ptr[0] = '(';
		ptr[1] = 'n';
		ptr[2] = 'u';
		ptr[3] = 'l';
		ptr[4] = 'l';
		ptr[5] = ')';
		ptr[6] = '\0';
		return (ptr);
	}

	for (i = 0; s[i] != '\0'; i++)
		;

	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);

	for (j = 0; j < i; j++)
		ptr[j] = s[j];

	ptr[j] = '\0';
	return (ptr);
}

/**
 * get_number - Converts an integer to a string and stores it in a memory block.
 * @n: Integer to be converted.
 *
 * Return: Pointer to the string representation of the integer, or NULL on error.
 */
char *get_number(int n)
{
	int i, len = 0, tmp;
	char *buf = NULL;

	/* Find the number of bytes to allocate */
	tmp = n;
	while (tmp >= 10 || tmp <= -10)
	{
		tmp /= 10;
		len++;
	}
	len++;
	if (n < 0)
		len++;

	buf = malloc(sizeof(char) * (len + 1));
	if (buf)
	{
		buf[len] = '\0';

		if (n < 0)
			buf[0] = '-';

		i = len - 1;
		while (n >= 10 || n <= -10)
		{
			tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
			buf[i] = tmp + '0';
			i--;
			n /= 10;
		}

		tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
		buf[i] = tmp + '0';
	}
}
