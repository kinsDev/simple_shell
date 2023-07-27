#include <unistd.h>

/**
 * sigint_handler - Signal handler for SIGINT (Ctrl+C) signal.
 * @s: The signal number (unused attribute indicates that the parameter is not used).
 *
 * This function is called when the shell receives the SIGINT signal, typically
 * when the user presses Ctrl+C. It writes a newline and the shell prompt ($)
 * to the standard output to provide a new line for user input.
 */
void sigint_handler(int __attribute__((unused)) s)
{
    write(1, "\n($) ", 5);
}

