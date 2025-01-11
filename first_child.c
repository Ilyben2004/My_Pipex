#include "pipex.h"

void first_child (int * pipefd, char ** command1, int fd)
{
    close(pipefd[0]);
    dup2(fd,0);
    dup2(pipefd[1],1);
    execve(command1[0], command1 , NULL);
    perror("");
    exit (0);
}