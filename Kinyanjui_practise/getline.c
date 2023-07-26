#include "header.h"

char* promptInput(const char* prompt)
{
    char* buffer = NULL;
    size_t len = 0;
    ssize_t command;

    printf("%s", prompt);

    command = getline(&buffer, &len, stdin);
    if (command == -1)
    {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    return buffer;
}
