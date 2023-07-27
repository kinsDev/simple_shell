#include "main.h"
#include "kkshell.h"

/**
 * _clear - Clears the terminal screen
 * @params: Pointer to the parameters (unused in this function)
 *
 * This function uses ANSI escape sequences to clear the terminal screen
 * and move the cursor to the top-left corner.
 *
 * Return: void
 */
void _clear(param_t *params)
{
    /* Unused parameter to avoid compiler warnings */
    (void)params;

    /* ANSI escape sequence to clear the terminal screen and move the cursor to (1,1) */
    _printf("\033[2J\033[1;1H");
}

