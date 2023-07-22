#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "kkshell :) ";
	char *lineptr = NULL;
	char *lineptr_cpy = NULL; // copy of the string to be passsed to strtok
	size_t n = 0;
	ssize_t line_read;
	const char *delim = " \n"; // we'll be usin a space and new line character as our delimiter for now

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
			printf("\n"); // print new line before exiting the shell
			return -1;
		}
                printf("%s\n", lineptr);
	}

	//dyhamically allocating space
	lineptr_cpy = malloc(sizeof(char) * line_read);
        if (lineptr_cpy== NULL)
	{
	       	perror("Eroor: Memory allocation");
                return -1;
        }

	strcpy(lineptr_cpy, lineptr);

	//tokenization
	token = strtok(lineptr, delim);
	while(token != NULL)
	{
		token_num++;
		token = strtok(NULL, delim);
	}
	token_num++;

	free(lineptr);

	return 0;
}
