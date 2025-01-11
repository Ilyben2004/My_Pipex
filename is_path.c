#include "pipex.h"

int     is_path(char * command)
{
    int i;

    i = 0;
    while (command[i])
    {
        if (command[i++] == '/')
            return (1);
    }
    return (0);
}