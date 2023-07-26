#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/* Return a formatted argument based on the type specifier. */
char *get_formatted_argument(char type, ...)
{
    va_list params;
    va_start(params, type);

    switch (type)
    {
        case 'c': return get_char_argument(va_arg(params, int));
        case 's': return get_string_argument(va_arg(params, char*));
        case 'd': case 'i': return get_number_argument(va_arg(params, int));
        case 'b': return get_binary_argument(va_arg(params, int));
        case 'r': return get_reversed_string(va_arg(params, char*));
        case 'R': return get_rot13_encoded_string(va_arg(params, char*));
        default: return NULL; // Error: Unsupported type specifier
    }
}

