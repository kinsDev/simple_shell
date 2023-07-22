#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "kkshell :) ";
	char *lineptr = NULL;
	char *lineptr_cpy = NULL; // copy of the string to be passsed to strtok
	size_t n = 0;
	ssize_t line_read;
	const char *delim = " \n"; // we'll be usin a space and new line character as our delimiter for now
	int token_num = 0, i;
	char *token;

	(void)ac;

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

	// space for string array
	argv = malloc(sizeof(char *) * token_num);

	// storing each token in an array
	token = strtok(lineptr_cpy, delim);

	for(i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	printf("%s\n", lineptr);
	// freeing up memeory that was previously allocated
	free(lineptr);

	return 0;
}
