#include "main.h"

char *get_location(char *cmd)
{
    int cmd_len, dir_len;
    char *file_path, *path, *path_cpy, *path_tkn;
    struct stat buffer;

    path = getenv("PATH");

    if (path)
    {
        /* duplicating the path sting & get length of the cmd passed */
        path_cpy = strdup(path);
        cmd_len = strlen(cmd);

        path_tkn = strtok(path_cpy, ":");

        while (path_tkn != NULL)
        {
            /* Get the length of the directory & allocate memory for storing the command & directory name*/
            dir_len = strlen(path_tkn);
            file_path = malloc(cmd_len + dir_len + 2);

            strcpy(file_path, path_tkn);
            strcat(file_path, "/");
            strcat(file_path, cmd);
            strcat(file_path, "\0");

            /* let's test if this file path actually exists and return it if it does, otherwise try the next directory */
            if (stat(file_path, &buffer) == 0)
            {
                free(path_cpy);

                return (file_path);
            }
            else
            {
                free(file_path);
                path_tkn = strtok(NULL, ":");
            }
        }

        /* returning NULL & freeing up memory for path_cpy */
        free(path_cpy);

        if (stat(cmd, &buffer) == 0)
        {
            return (cmd);
        }

        return (NULL);
    }

    return (NULL);
}
