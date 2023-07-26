#include "header.h"
void execute_command(char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Failed to create a child process");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        char *args[] = {"/bin/ls", "-l", NULL};
        //execvp(command, args);
        // If execvp returns, there was an error
	execve("/bin/ls", args, NULL);
        perror("Execution failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}
