#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE
#include <stdio.h>
#include "lists.h"

/**
 * get_char - Allocates memory for a single character and the null terminator.
 * @c: The character to store in the allocated memory.
 *
 * Return: Pointer to the allocated memory, NULL if error.
 */
char *get_char(char c);

/**
 * get_string - Allocates memory for a string and the null terminator.
 * @s: The string to store in the allocated memory.
 *
 * Return: Pointer to the allocated memory, NULL if error.
 */
char *get_string(char *s);

/**
 * get_number - Allocates memory for an integer as a string.
 * @n: The integer to store in the allocated memory.
 *
 * Return: Pointer to the allocated memory, NULL if error.
 */
char *get_number(int n);

/**
 * get_arg - Allocates memory for a variable argument list.
 * @type: The type of the parameter to store in the allocated memory.
 * @...: Variable argument list.
 *
 * Return: Pointer to the allocated memory, NULL if error.
 */
char *get_arg(char type, ...);

/**
 * get_binary - Converts an unsigned integer to its binary representation.
 * @n: The integer to convert.
 *
 * Return: Pointer to the binary representation as a string.
 */
char *get_binary(unsigned int n);

/**
 * get_rev - Reverses a string.
 * @s: The string to reverse.
 *
 * Return: Pointer to the reversed string.
 */
char *get_rev(char *s);

/**
 * get_rot13 - Applies the ROT13 cipher to a string.
 * @s: The string to apply ROT13 to.
 *
 * Return: Pointer to the ROT13 ciphered string.
 */
char *get_rot13(char *s);

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the concatenated string.
 */
char *str_concat(char *s1, char *s2);

/**
 * string_nconcat - Concatenates two strings up to n bytes.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of bytes to concatenate from s2.
 *
 * Return: Pointer to the concatenated string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n);

/**
 * _strlen - Computes the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s);

/**
 * _printf - Custom printf function that supports basic formatting.
 * @format: The format string containing the text and format specifiers.
 * @...: Variable argument list.
 *
 * Return: The number of characters printed (excluding the null byte),
 *         or -1 if an error occurs.
 */
int _printf(const char *format, ...);

/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c);

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, a positive value if s1 > s2,
 *         and a negative value if s1 < s2.
 */
int _strcmp(char *s1, char *s2);

/**
 * _strcmp_n - Compares two strings up to a given number of characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 *
 * Return: 0 if the strings are equal up to the given number of characters,
 *         a positive value if s1 > s2, and a negative value if s1 < s2.
 */
int _strcmp_n(char *s1, char *s2, int n);

/* Function prototypes */
param_t *init_param(char **argv, char **env);
void print_environment_list(list_t *head);
void print_all_aliases(param_t *params);
void free_alias_list(list_t *head);

#endif /* _MAIN_H_ */

