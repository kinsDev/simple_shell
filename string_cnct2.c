#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "kkshell.h"
#include "main.h"

/**
 * _str_copy - Copies a string from source to destination.
 * @src: Pointer to the source string.
 * @dest: Pointer to the destination string.
 *
 * Return: Pointer to the destination string.
 */
char *_str_copy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';

	return (dest);
}

/**
 * _str_compare - Compares two strings.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: An integer less than, equal to, or greater than 0 if s1 is,
 * respectively, less than, equal to, or greater than s2.
 */
int _str_compare(char *s1, char *s2)
{
	int res = 0;

	do {
		res = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (res == 0);

	return (res);
}

/**
 * _str_compare_n - Compares n bytes of two strings.
 * @s1: String 1.
 * @s2: String 2.
 * @n: Number of bytes to compare.
 *
 * Return: An integer less than, equal to, or greater than 0 if s1 is,
 * respectively, less than, equal to, or greater than s2.
 */
int _str_compare_n(char *s1, char *s2, int n)
{
	int i = 0, res = *s1 - *s2;

	while (i <= n)
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}

/**
 * _str_to_int - Converts a string to an integer.
 * @s: String to evaluate.
 *
 * Return: The value of the first number in the string.
 */
int _str_to_int(char *s)
{
	int num, tmp, len, mul = 1;

	num = 0;
	tmp = 0;
	len = _str_length(s);
	len--;
	while (len >= 0)
	{
		tmp = num;
		num = num + (s[len] - '0') * mul;
		if (num < tmp || num > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (num);
}

