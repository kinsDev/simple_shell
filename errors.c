#include <unistd.h>
#include "kkshell.h"
#include "main.h"

/**
 * write_error - Write error message to stderr
 * @params: Parameters struct containing info about the command and program
 * @msg: Error message to print
 *
 * This function takes a parameter struct containing information about the current
 * command and program and an error message to print to stderr. The function
 * builds an error message string from the information in the parameter struct
 * and the error message, and writes it to stderr using the write system call.
 *
 * Parameters:
 *   @params: A pointer to a param_t struct containing the following fields:
 *            - argv: An array of strings containing the command and its arguments.
 *            - lineCount: An integer representing the current line count.
 *            - args: An array of strings containing the arguments passed to the command.
 *   @msg: The error message to be displayed.
 */
void write_error(param_t *params, char *msg)
{
    /* Initialize an error buffer to store the constructed error message*/
    char errBuffer[1024] = {0};
    char *writeHead = errBuffer, *bufPtr = errBuffer;

    /* Construct the error message using the information from the parameter struct*/
    _strcpy(writeHead, params->argv[0]);
    writeHead = bufPtr + _strlen(bufPtr);
    _strcpy(writeHead, ": ");
    writeHead = bufPtr + _strlen(bufPtr);
    _strcpy(writeHead, get_number(params->lineCount));
    writeHead = bufPtr + _strlen(bufPtr);
    _strcpy(writeHead, ": ");
    writeHead = bufPtr + _strlen(bufPtr);
    _strcpy(writeHead, params->args[0]);
    writeHead = bufPtr + _strlen(bufPtr);
    _strcpy(writeHead, ": ");
    writeHead = bufPtr + _strlen(bufPtr);
    _strcpy(writeHead, msg);
    writeHead = bufPtr + _strlen(bufPtr);

    /* Write the error message to stderr using the write system call*/
    write(STDERR_FILENO, errBuffer, _strlen(bufPtr));
}

