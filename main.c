#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "kkshell :) ";
	char *lineptr;
	size_t n = k0;

	(void)ac;
	(void)argv;

	// in a getline function 1 stands for success
	// Infinite loop
	while(1)
	{	
		printf("%s", prompt);
	       	getline(&lineptr, &n, stdin);
                printf("%s\n", lineptr);

		free(lineptr);
	}
	return 0;
}
