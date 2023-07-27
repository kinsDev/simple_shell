#ifndef _MAIN_H_
#define _MAIN_H_

/**
 * @file main.h
 * Header file containing function prototypes and macros.
 */

#define NULL_PTR -1
#define WRONG_SPECIFIER -2

/* Allocate memory for a character and null-terminate it. */
char *get_char(char c);

/* Allocate memory for a string and null-terminate it. */
char *get_string(char *s);

/* Allocate memory for an integer and null-terminate it. */
char *get_number(int n);

/* Allocate memory for passed-in parameters. */
char *get_arg(char type, ...);

/* Convert an unsigned integer to binary representation. */
char *get_binary(unsigned int n);

/* Reverse a given string. */
char *get_rev(char *s);

/* Apply the ROT13 cipher to a given string. */
char *get_rot13(char *s);

/* Concatenate two strings. */
char *str_concat(char *s1, char *s2);

/* Concatenate two strings, limiting the second string to n bytes. */
char *string_nconcat(char *s1, char *s2, unsigned int n);

/* Calculate the length of a given string. */
int _strlen(char *s);

/* Custom implementation of printf with support for format specifiers. */
int _printf(const char *format, ...);

/* Locate the first occurrence of a character in a string. */
char *_strchr(char *s, char c);

/* Convert a string to an integer. */
int _atoi(char *s);

/* Compare two strings. */
int _strcmp(char *s1, char *s2);

/* Compare two strings up to n characters. */
int _strcmp_n(char *s1, char *s2, int n);

#endif /* _MAIN_H_ */

