#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h" // Include the header file where BUFSIZE and any custom functions are defined

/**
 * assign_lineptr - assigns the line var for get_input_line
 * @lineptr: Buffer that stores the input str
 * @n: size of line
 * @buffer: str that is been called to line
 * @j: size of buffer
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t j)
{
    if (*lineptr == NULL)
    {
        if (j > BUFSIZ) // Change BUFSIZE to BUFSIZ
            *n = j;
        else
            *n = BUFSIZ;
        *lineptr = buffer;
    }
    else if (*n < j)
    {
        if (j > BUFSIZ) // Change BUFSIZE to BUFSIZ
            *n = j;
        else
            *n = BUFSIZ;
        *lineptr = buffer;
    }
    else
    {
        strcpy(*lineptr, buffer); // Use strcpy instead of _strcpy
        free(buffer);
    }
}

/**
 * get_input_line - Read input from stream
 * @lineptr: Buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_input_line(char **lineptr, size_t *n, FILE *stream)
{
    int i;
    static ssize_t input;
    ssize_t retval;
    char *buffer;
    char t = 'z';

    if (input == 0)
        fflush(stream);
    else
        return (-1);
    input = 0;

    buffer = malloc(sizeof(char) * BUFSIZ); // Change BUFSIZE to BUFSIZ
    if (buffer == NULL)
        return (-1);
    while (t != '\n')
    {
        i = read(STDIN_FILENO, &t, 1);
        if (i == -1 || (i == 0 && input == 0))
        {
            free(buffer);
            return (-1);
        }
        if (i == 0 && input != 0)
        {
            input++;
            break;
        }
        if (input >= BUFSIZ) // Change BUFSIZE to BUFSIZ
            buffer = realloc(buffer, input + 1); // Use realloc instead of _realloc
        buffer[input] = t;
        input++;
    }
    buffer[input] = '\0';
    assign_lineptr(lineptr, n, buffer, input);
    retval = input;
    if (i != 0)
        input = 0;
    return (retval);
}

