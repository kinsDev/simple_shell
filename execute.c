#include "main.h"

void execmd(char **argv)
{
	char *cmd = NULL, *typed_cmd = NULL;

	if(argv != NULL)
	{
		/* get the command keyed i by the end user */
		cmd = argv[0];

		/* generating path to the keyed in command */
		typed_cmd = get_location(cmd);

		/* executing the command that we got using execve */
		if (execve(typed_cmd, argv, NULL) == -1)
		{
			perror("Error: command not available");
		}
	}
}
