
#include "pipex.h"
int  main(int argc , char * argv[]) 
{
    int fd;
    int pipefd[2];

    fd = open(argv[1],O_RDONLY);
    unlink(argv[4]);
    int fd2 = open(argv[4],O_WRONLY | O_CREAT , 0666);
    char **command1 = ft_split(argv[2] , ' ');
    char **command2 = ft_split(argv[3] , ' ');
    pipe(pipefd);
    pid_t pid = fork();
    if(pid == 0)
        first_child (pipefd , command1 , fd);
    else
    {
        wait(NULL);
        pid_t pid2 = fork();
        if (pid2 == 0)
            second_child(pipefd,command2, fd2);
    }
    free_splited(command1,command2);
    return 0;
}