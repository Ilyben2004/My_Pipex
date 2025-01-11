#include "pipex.h"

char **extract_paths (char **envp)
{
    int i;

    i = 0;
    char ** paths;
    paths = NULL;
    while (envp[i])
    {
        if (ft_strnstr (envp[i] , "PATH=" , 5))
            return (ft_split(envp[i] + 5,':'));
        i++;
    }
    return (NULL);
}