#include "header.h"

int main()
{
	char command[MAX_COMMAND_LENGTH];
	while (1)
	{
		
		//promptInput("$ ");
		printf("#cisfun# ");
		// implement exit command
		if (strcmp(command, "exit") == 0)
		{
		break;
		}
		// implement environmental variable
		if (strcmp(command, "env") == 0)
		{
			print_environment();
		}
		// // Handle "end of file" condition (Ctrl+D)
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nEnd of task 1\n");
			break;
		}
		// Remove the trailing newline character from the command
		 command[strcspn(command, "\n")] = '\0';
		 //function to execute command input
		 execute_command(command);
	}	
	return 0;
}
