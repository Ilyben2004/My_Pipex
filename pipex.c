
#include "pipex.h"
int  main(int argc , char * argv[]) {
   
    int fd;
    int pipefd[2];

    fd = open(argv[1],O_RDONLY);
    unlink(argv[4]);
    int fd2 = open(argv[4],O_WRONLY | O_CREAT);

    pipe(pipefd);
    pid_t pid = fork();
    if(pid == 0)
    {
        char **command1 = ft_split(argv[2] , ' ');
        close(pipefd[0]);
        dup2(fd,0);
        dup2(pipefd[1],1);
        execve(ft_strjoin("/bin/",command1[0]), command1 , LL);
    }

    else  
    {
        char **command2 = ft_split(argv[3] , ' ');
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
        close(pipefd[1]);
        dup2(fd2,1);
        dup2(pipefd[0],0);
        execve(ft_strjoin("/bin/",command2[0]), command2 , NULL);
        printf("%s is : \n",command2[0]);
        }
    }
    return 0;
}