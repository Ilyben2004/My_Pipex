
#include "pipex.h"

static void pipex_init(pipex_t *pipex_vars , char * argv[] , char *envp[] )
{
    pipex_vars->command1 = ft_split(argv[2] , ' ');
    pipex_vars-> command2 = ft_split(argv[3] , ' ');
    pipex_vars->command1[0] = ft_check_command(pipex_vars->command1[0] , envp);
    pipex_vars->command2[0] = ft_check_command(pipex_vars->command2[0] , envp);
    if (access(argv[1] ,F_OK == -1))
    {
        printf("bash: %s: No such file or directory\n",argv[1]);
        free(pipex_vars->command1[0]);
        pipex_vars->command1[0] = NULL;
    }
    else
    {
        if (access(argv[1] ,R_OK == -1))
        {
            printf("permseeion denied %s \n",argv[1]);
            pipex_vars->command1[0] = NULL;
        }
    }

    pipex_vars->fd = open(argv[1],O_RDONLY);
    unlink(argv[4]);
    pipex_vars->fd2 = open(argv[4],O_WRONLY | O_CREAT , 0666);
    pipe(pipex_vars->pipefd);
}

int  main(int argc , char * argv[], char *envp[]) 
{
    pipex_t *pipex_vars;
    pid_t pid;
    pid_t pid2;

    pipex_vars = malloc(sizeof(pipex_t));
    if(!pipex_vars)
        return (0);
    pipex_init(pipex_vars, argv, envp);
    pid = fork();
    if(pid == 0 && pipex_vars->command1[0])
        first_child (pipex_vars->pipefd , pipex_vars->command1 , pipex_vars->fd);
    else if (pid > 0)
    {
    
        if (!pipex_vars->command2[0])
            return (0);
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0)
            second_child(pipex_vars->pipefd,pipex_vars->command2, pipex_vars->fd2);
    }
    free_splited(pipex_vars->command1,pipex_vars->command2);
    return 0;
}