#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "kkshell :) ";
	char *lineptr;
	size_t n = 0;
	ssize_t line_read;

	(void)ac;
	(void)argv;

	// in a getline function 1 stands for success
	// Infinite loop
	while(1)
	{	
		printf("%s", prompt);
	        line_read = getline(&lineptr, &n, stdin);

		/* check if getline() reached EOF or user CTRL +D */
		if(line_read == -1)
		{
			return -1;
		}
                printf("%s\n", lineptr);

		free(lineptr);
	}
	return 0;
}
