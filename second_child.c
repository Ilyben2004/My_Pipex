#include "pipex.h"

void second_child(int * pipefd, char ** command2, int fd2)
{
   close(pipefd[1]);
   dup2(fd2,1);
   dup2(pipefd[0],0);
   execve(command2[0], command2 , NULL);
   perror("");
   exit (0);
}