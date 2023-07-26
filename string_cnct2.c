#include <string.h>
#include <limits.h>
#include "kkshell.h"
#include "main.h"

/**
 * _strcpy - Copies a string to another memory address.
 * @src: Pointer to the source string.
 * @dest: Pointer to the destination address.
 *
 * Return: Pointer to the destination.
 */
char *_strcpy(char *dest, const char *src)
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
 * _strcmp - Compares two strings.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: Integer less than, equal to, or greater than 0 if s1 is, respectively,
 * less than, equal to, or greater than s2.
 */
int _strcmp(char *s1, char *s2)
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
 * _strcmp_n - Compares n bytes of two strings.
 * @s1: String 1.
 * @s2: String 2.
 * @n: Number of bytes to compare.
 *
 * Return: Integer less than, equal to, or greater than 0 if s1 is, respectively,
 * less than, equal to, or greater than s2.
 */
int _strcmp_n(char *s1, char *s2, int n)
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
 * _atoi - Converts a string to an integer.
 * @s: String to evaluate.
 *
 * Return: The value of the first number in the string.
 */
int _atoi(char *s)
{
    int n, tmp, len, mul = 1;

    n = 0;
    tmp = 0;

    len = _strlen(s);
    len--;
    while (len >= 0)
    {
        tmp = n;
        n = n + (s[len] - '0') * mul;
        if (n < tmp || n > INT_MAX)
            return (-1);
        len--;
        mul *= 10;
    }

    return (n);
}

