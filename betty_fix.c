#include "main.h"
#include "kkshell.h"

/**
 * clear_screen - Clears the terminal screen
 * @params: Pointer to the parameter structure
 *
 * Return: void
 */
void clear_screen(param_t *params)
{
    /* Silence unused parameter warning */
    (void)params;

    /* Send escape sequences to clear the terminal */
    _printf("\033[2J\033[1;1H");
}

