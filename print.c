#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

// Function prototypes
int flush_buffer(char *buffer, int *index);
int print_arg(char *arg);
void get_type(char *format, int *index);

/**
 * _printf - Output text to standard output specified by format.
 * @format: Directives for outputting text.
 *
 * Return: Number of characters output.
 */
int _printf(const char *format, ...)
{
	va_list params;
	int high, sum = 0, index = 0;
	char *arg = NULL;
	char buffer[BUFFER_SIZE] = {0};

	if (!format)
		return (-1);

	va_start(params, format);

	/* Special case for only one % sign */
	if (_strlen((char *)format) == 1 && format[0] == '%')
	{
		va_end(params);
		return (-1);
	}

	high = 0;
	while (1)
	{
		if (index == BUFFER_SIZE)
		{
			/* Flush the buffer when it is full */
			sum += flush_buffer(buffer, &index);
		}

		if (format[high] == '%')
		{
			get_type((char *)format, &high);

			/* Process the specifier */
			switch (format[high])
			{
			case 'c':
				buffer[index] = (char) va_arg(params, int);
				index++;
				high++;
				continue;
			case 's':
				arg = get_arg('s', va_arg(params, char*));
				break;
			case 'd':
			case 'i':
				arg = get_arg('d', va_arg(params, int));
				break;
			case 'b':
				arg = get_arg('b', va_arg(params, int));
				break;
			case 'r':
				arg = get_arg('r', va_arg(params, char *));
				break;
			case 'R':
				arg = get_arg('R', va_arg(params, char *));
				break;
			case '%':
				arg = malloc(2);
				arg[0] = '%';
				arg[1] = '\0';
				break;
			case '\0':
				buffer[index] = '%';
				index++;
				continue;
			default: /* Unknown specifier */
				arg = malloc(3);
				arg[0] = '%';
				arg[1] = format[high];
				arg[2] = '\0';
			}

			if (!arg)
			{
				va_end(params);
				free(arg);
				return (-1);
			}

			sum += flush_buffer(buffer, &index);
			sum += print_arg(arg);
			free(arg);
			high++;
		}
		else if (format[high] != '\0')
		{
			buffer[index] = format[high];
			index++;
			high++;
		}
		else
		{
			sum += flush_buffer(buffer, &index);
			break;
		}
	}

	va_end(params);
	return (sum);
}

/**
 * flush_buffer - Print out the buffer up to index and reset.
 * @buffer: Buffer string.
 * @index: Index.
 *
 * Return: Total number of characters printed.
 */
int flush_buffer(char *buffer, int *index)
{
	int num = 0;

	num = write(1, buffer, *index);
	*index = BUFFER_SIZE - 1;

	/* Reset the buffer to 0 */
	while (*index >= 0)
	{
		buffer[*index] = 0;
		*index -= 1;
	}
	*index = 0;
	return (num);
}

/**
 * print_arg - Print argument string.
 * @arg: String.
 *
 * Return: Number of bytes printed.
 */
int print_arg(char *arg)
{
	return (write(1, arg, _strlen(arg)));
}

/**
 * get_type - Get type from the specifier from the format string.
 * This function skips spaces, finds a specifier, and moves the index
 * to the specifier.
 * @format: Format string.
 * @index: Current index of format string.
 */
void get_type(char *format, int *index)
{
	do {
		*index += 1;
	} while (format[*index] == ' ');
}

