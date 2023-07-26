#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string argument
 * @s2: second string argument
 *
 * Return: pointer to a newly allocated memory with concatenated strings,
 *         NULL on failure or if both s1 and s2 are NULL
 */
char *str_concat(char *s1, char *s2)
{
    char *ptr;
    int i = 0;
    int j = 0;
    int x = 0;

    /* If s1 is NULL, set it to an empty string */
    if (s1 == NULL)
    {
        s1 = "";
    }
    /* If s2 is NULL, set it to an empty string */
    if (s2 == NULL)
    {
        s2 = "";
    }

    /* Calculate the length of s1 */
    while (s1[i] != '\0')
    {
        i++;
    }

    /* Calculate the length of s2 */
    while (s2[j] != '\0')
    {
        j++;
    }

    /* Allocate memory to hold concatenated strings */
    ptr = malloc((i * sizeof(char)) + (j * sizeof(char)) + 1);
    if (ptr == NULL)
    {
        return (NULL);
    }

    /* Copy characters from s1 to ptr */
    for (i = 0; s1[i] != '\0'; i++)
    {
        ptr[i] = s1[i];
        x++;
    }

    /* Copy characters from s2 to ptr */
    for (j = 0; s2[j] != '\0'; j++)
    {
        ptr[x] = s2[j];
        x++;
    }

    ptr[x] = '\0'; /* Null-terminate the concatenated string */
    return (ptr);
}

/**
 * string_nconcat - concatenates two strings up to n bytes from s2
 * @s1: first string argument
 * @s2: second string argument
 * @n: amount of bytes from s2 to concatenate
 *
 * Return: pointer to a newly allocated memory with concatenated strings,
 *         NULL on failure or if both s1 and s2 are NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *ptr;
    unsigned int i = 0;
    unsigned int j = 0;

    /* If s1 is NULL, set it to an empty string */
    if (s1 == NULL)
    {
        s1 = "";
    }

    /* If s2 is NULL, set it to an empty string */
    if (s2 == NULL)
    {
        s2 = "";
    }

    /* Calculate the length of s1 */
    while (s1[i] != '\0')
    {
        i++;
    }

    /* Calculate the length of s2 */
    while (s2[j] != '\0')
    {
        j++;
    }

    /* If n is greater than s2 length, set n to s2 length */
    if (n > j)
    {
        n = j;
    }

    /* Allocate memory to hold concatenated strings */
    ptr = malloc(sizeof(char) * (n + i) + 1);
    if (ptr == NULL)
    {
        return (NULL);
    }

    /* Copy characters from s1 to ptr */
    for (i = 0; s1[i] != '\0'; i++)
    {
        ptr[i] = s1[i];
    }

    /* Copy characters from s2 to ptr up to n bytes */
    for (j = 0; j < n; j++)
    {
        ptr[i + j] = s2[j];
    }

    ptr[i + j] = '\0'; /* Null-terminate the concatenated string */
    return (ptr);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: 0 if null, else length without null byte
 */
int _strlen(char *s)
{
    int length = 0;

    if (s == NULL)
    {
        return (0);
    }

    /* Calculate the length of the string */
    for (length = 0; s[length] != '\0'; length++)
        ;

    return (length);
}

/**
 * _strdup - copy a string to a new allocated block of memory
 * @str: string
 *
 * Return: pointer to duplicated string, NULL if insufficient memory
 */
char *_strdup(char *str)
{
    int len = 0; /* index of terminating null byte */
    char *ptr = NULL;

    /* Check if the input string is NULL */
    if (!str)
        return (NULL);

    /* Calculate the length of the input string */
    while (*str)
    {
        len++;
        str++;
    }

    /* Allocate memory to hold the duplicated string */
    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (ptr)
    {
        /* Copy characters from the input string to the duplicated string */
        while (len >= 0)
            *(ptr + len--) = *(str--);
    }

    return (ptr);
}

/**
 * _strchr - locates a character in a string
 * @s: where to start looking
 * @c: values to find
 *
 * Return: pointer to beginning of memory area
 */
char *_strchr(char *s, char c)
{
    int i;

    i = 0;
    /* Iterate through the string to find the character c */
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }

    /* If c is null byte, return the pointer to the null byte */
    if (c == '\0')
        return (&s[i]);

    /* Return NULL if the character c is not found */
    return (0);
}

