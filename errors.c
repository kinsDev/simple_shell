#ifndef ERRORS_H
#define ERRORS_H

#include <unistd.h>
#include "kkshell.h"
#include "main.h"

/**
 * write_error - Write error message to stderr.
 * @params: Pointer to the parameter struct containing info about the command and program.
 * @msg: Error message to print.
 *
 * This function takes a pointer to the parameter struct (params) containing information
 * about the current command and program and an error message (msg) to print to stderr.
 * The function builds an error message string from the information in the parameter
 * struct and the error message and writes it to stderr using the write system call.
 */
void write_error(param_t *params, char *msg)
{
    char errBuffer[1024] = {0};
    char *writeHead = errBuffer, *bufPtr = errBuffer;

    /* Copy the program name to the error buffer */
    _strcpy(writeHead, params->argv[0]);
    writeHead = bufPtr + _strlen(bufPtr);

    /* Add a colon and space */
    _strcpy(writeHead, ": ");
    writeHead = bufPtr + _strlen(bufPtr);

    /* Add the line number */
    _strcpy(writeHead, get_number(params->lineCount));
    writeHead = bufPtr + _strlen(bufPtr);

    /* Add a colon and space */
    _strcpy(writeHead, ": ");
    writeHead = bufPtr + _strlen(bufPtr);

    /* Add the command name */
    _strcpy(writeHead, params->args[0]);
    writeHead = bufPtr + _strlen(bufPtr);

    /* Add a colon and space */
    _strcpy(writeHead, ": ");
    writeHead = bufPtr + _strlen(bufPtr);

    /* Add the error message */
    _strcpy(writeHead, msg);
    writeHead = bufPtr + _strlen(bufPtr);

    /* Write the error message to stderr */
    write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}

#endif /* ERRORS_H */

