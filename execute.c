#include "main.h"

void execmd(char **argv)
{
	char *command = NULL;

	if(argv != NULL)
	{
		/* get the command keyed i by the end user */
		command = argv[0];

		/* executing the command that we got using execve */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error: command not available");
		}
	}
}
