
#include "pipex.h"

static void	pipex_init(pipex_t *pipex_vars, char *argv[], char *envp[])
{
	int	i;

	i = 0;
	pipex_vars->command1 = ft_split(argv[2], ' ');
	pipex_vars->command2 = ft_split(argv[3], ' ');
	
	pipex_vars->command2[0] = ft_check_command(&(pipex_vars->command2[0]), envp);
	pipex_vars->fd = open(argv[1], O_RDONLY);
	if (pipex_vars->fd == -1)
	{
		perror(argv[1]);
		while (pipex_vars->command1[i])
			free(pipex_vars->command1[i++]);
		pipex_vars->command1[0] = NULL;
	}
	else
		pipex_vars->command1[0] = ft_check_command(&(pipex_vars->command1[0]), envp);

	pipex_vars->fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex_vars->fd2 == -1)
	{
		i = 0;
		perror(argv[4]);
		while (pipex_vars->command2[i])
			free(pipex_vars->command2[i++]);
		pipex_vars->command2[0] = NULL;
	}
	pipe(pipex_vars->pipefd);
}

int	main(int argc, char *argv[], char *envp[])
{
	pipex_t	*pipex_vars;
	pid_t	pid;
	pid_t	pid2;

	if (argc == 5)
	{
		pipex_vars = malloc(sizeof(pipex_t));
		if (!pipex_vars)
			return (0);
		pipex_init(pipex_vars, argv, envp);
		pid = fork();
		if (pid == 0 && pipex_vars->command1[0])
		{
			printf("i stopeed here first child");
			first_child(pipex_vars->pipefd, pipex_vars->command1,
				pipex_vars->fd);
		}
		else if (pid > 0)
		{
			if (!pipex_vars->command2[0])
				return (0);
			pid2 = fork();
			if (pid2 == 0 && pipex_vars->command2[0])
			{
				printf("i stopped here second child");
				second_child(pipex_vars->pipefd, pipex_vars->command2,
					pipex_vars->fd2);
			}
		}
		free_splited(pipex_vars->command1, pipex_vars->command2);
		free(pipex_vars);
	}
	return (0);
}
