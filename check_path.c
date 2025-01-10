#include "pipex.h"

char * check_path(char * command)
{
    int i;
    int ispath;

    ispath = 0;
    i = 0;
    while (command[i])
    {
        if (command[i] == '/')
            ispath = 1;
        i++;
    }
    if(ispath)
        return (command);
    return (ft_strjoin("/bin/ls" , command));

}