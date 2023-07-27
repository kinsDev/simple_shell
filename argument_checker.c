#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_formatted_argument - Returns a formatted argument based on the type specifier.
 *
 * @type: Type specifier indicating the desired formatting ('c', 's', 'd', 'i',
 *         'b', 'r', 'R').
 * @...: Variable number of arguments depending on the type specifier.
 *
 * This function takes a type specifier and a variable number of arguments and
 * returns a dynamically allocated string representation of the argument based on the type specifier.
 *
 *    The supported type specifiers are:
 *   - 'c': Char argument is passed as int and returned as a string.
 *   - 's': String argument is passed as char* and returned as a string.
 *   - 'd' or 'i': Integer argument is passed as int and returned as a string.
 *   - 'b': Integer argument is passed as int and returned as a binary string.
 *   - 'r': String argument is passed as char* and returned as a reversed string.
 *   - 'R': String argument is passed as char* and returned as a ROT13 string.
 *
 * Return: A dynamically allocated string representation of the argument based
 *        on the type specifier,
 *         or NULL if an unsupported type specifier is provided.
 */
char *get_formatted_argument(char type, ...)
{
	va_list params;
	char *result = NULL;

	va_start(params, type);
	switch (type)
	{
	case 'c':
		result = get_char_argument(va_arg(params, int));
		break;
	case 's':
		result = get_string_argument(va_arg(params, char*));
		break;
	case 'd':
	case 'i':
		result = get_number_argument(va_arg(params, int));
		break;
	case 'b':
		result = get_binary_argument(va_arg(params, int));
		break;
	case 'r':
		result = get_reversed_string(va_arg(params, char*));
		break;
	case 'R':
		result = get_rot13_encoded_string(va_arg(params, char*));
		break;
	default:
		result = NULL; /* Error: Unsupported type specifier */
	}

	va_end(params);
	return result;
}

