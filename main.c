#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "kkshell :) ";
	char *lineptr;
	size_t n = 0l

	(void)ac;
	(void)argv;

        printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return 0;
}
