#include <stdlib.h>

/**
 * move_left - Removes leading 0's from a binary string.
 * @buffer: The buffer containing the binary string.
 * @buffer_size: The size of the buffer.
 * @num: The number of digits in the binary number.
 *
 * Return: Pointer to the buffer.
 */
char *move_left(char *buffer, int buffer_size, int num)
{
    int i;
    char *ptr;

    for (i = 0, ptr = (buffer + buffer_size - num); i < num; i++, ptr++)
        *(buffer + i) = *ptr;
    *(buffer + num) = '\0';
    return (buffer);
}

/**
 * get_binary - Converts an unsigned integer to a binary string.
 * @n: The integer to convert.
 *
 * Return: Pointer to the binary string.
 */
char *get_binary(unsigned int n)
{
    char *binary_str = NULL;
    unsigned int i, num = 0, buffer_size = 0;

    if (n == 0)
    {
        binary_str = malloc(2);
        if (binary_str)
        {
            binary_str[0] = '0';
            binary_str[1] = '\0';
        }
        return (binary_str);
    }

    buffer_size = sizeof(unsigned int) * 8 + 1;
    binary_str = malloc(buffer_size);
    if (binary_str)
    {
        for (i = 0; i < buffer_size; i++)
        {
            binary_str[i] = '0';
        }
        binary_str[buffer_size - 1] = '\0';

        i = buffer_size - 2;
        while (n != 0)
        {
            binary_str[i] = (n % 2 == 0) ? '0' : '1';
            num++;
            n = n / 2;
            i--;
        }
        num++;
        binary_str = move_left(binary_str, buffer_size, num);
    }
    return (binary_str);
}

/**
 * get_char - Returns a copied character.
 * @c: The character to be copied.
 *
 * Return: Pointer to the copied character.
 */
char *get_char(char c)
{
    char *ptr = NULL;

    ptr = malloc(2);
    if (ptr == NULL)
    {
        return (NULL);
    }
    ptr[0] = c;
    ptr[1] = '\0';
    return (ptr);
}

/**
 * get_string - Returns a new duplicated string.
 * @s: The string to be copied.
 *
 * Return: Null if the string is NULL, else a pointer to the copied string.
 */
char *get_string(char *s)
{
    char *duplicated_str = NULL;
    int i, j;

    if (s == NULL)
    {
        duplicated_str = malloc(7);
        if (duplicated_str == NULL)
            return (NULL);
        duplicated_str[0] = '(';
        duplicated_str[1] = 'n';
        duplicated_str[2] = 'u';
        duplicated_str[3] = 'l';
        duplicated_str[4] = 'l';
        duplicated_str[5] = ')';
        duplicated_str[6] = '\0';
        return (duplicated_str);
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        ;
    }

    duplicated_str = (char *)malloc(i * sizeof(char) + 1);
    if (duplicated_str == NULL)
    {
        return (NULL);
    }

    for (j = 0; j < i; j++)
    {
        duplicated_str[j] = s[j];
    }
    duplicated_str[j] = '\0';
    return (duplicated_str);
}

/**
 * get_number - Converts an integer to a string.
 * @n: The integer.
 *
 * Return: Pointer to the integer string, NULL on error.
 */
char *get_number(int n)
{
    int i, length = 0, tmp;
    char *buffer = NULL;

    /* Find the number of bytes to allocate */
    tmp = n;
    while (tmp >= 10 || tmp <= -10)
    {
        tmp /= 10;
        length++;
    }
    length++;
    if (n < 0)
        length++;

    buffer = malloc(sizeof(char) * (length + 1));
    if (buffer)
    {
        buffer[length] = '\0';

        if (n < 0)
        {
            buffer[0] = '-';
        }

        i = length - 1;
        while (n >= 10 || n <= -10)
        {
            tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
            buffer[i] = tmp + '0';
            i--;
            n /= 10;
        }
        tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
        buffer[i] = tmp + '0';
    }
    return (buffer);
}

