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
    free(command);
    return (ft_strjoin("/bin/ls" , command));

}
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

void first_child (int * pipefd, char ** command1, int fd)
{
    close(pipefd[0]);
    dup2(fd,0);
    dup2(pipefd[1],1);
    execve(command1[0], command1 , NULL);
    perror("");
    exit (0);
}

void second_child(int * pipefd, char ** command2, int fd2)
{
   close(pipefd[1]);
   dup2(fd2,1);
   dup2(pipefd[0],0);
   execve(command2[0], command2 , NULL);
   perror("");
   exit (0);
}