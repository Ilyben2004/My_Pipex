/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:00:10 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:13 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int args_checker(int argc , char *argv[])
{
	int i;
	int valid;

	valid = -1;
	i = 1;
	if (argc==5)
	{
		while (i < 5)
		{
			if (!(*argv[i]))
				valid = -1;
			i++;

		}
	
	}
	else
		valid = -1;
	if (valid == -1)
		write(1,"please enter a valid arguments!",31);
	return (valid);
}
static void	handle_open_fail(char *file, char **command)
{
	int	i;

	i = 0;
	perror(file);
	while (command && command[i])
	{
		free(command[i]);
		command[i] = NULL;
		i++;
	}
}

static void	pipex_init(t_pipex *pipex_vars, char *argv[], char *envp[])
{
	pipex_vars->command1 = ft_split(argv[2], " \t");
	pipex_vars->command2 = ft_split(argv[3], " \t");
	if (!pipex_vars->command1 || !pipex_vars->command2)
		return ;
	pipex_vars->fd = open(argv[1], O_RDONLY);
	if (pipex_vars->fd == -1)
		handle_open_fail(argv[1], pipex_vars->command1);
	else
		pipex_vars->command1[0] = ft_check_command(&(pipex_vars->command1[0]),
				envp);
	pipex_vars->fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex_vars->fd2 == -1)
		handle_open_fail(argv[4], pipex_vars->command2);
	if (pipe(pipex_vars->pipefd) == -1)
		perror("Pipe fail");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex_vars;
	pid_t	pid;
	pid_t	pid2;

	if (args_checker(argc,argv) == -1)
		return (0);
	pipex_vars = malloc(sizeof(t_pipex));
	if (!pipex_vars)
		return (0);
	pipex_init(pipex_vars, argv, envp);
	if (!pipex_vars->command1 || !pipex_vars->command2)
		return (free_struct(pipex_vars), 0);
	pid = fork();
	if (pid == 0)
		first_child(pipex_vars->pipefd, pipex_vars->command1, pipex_vars->fd,
			envp);
	pid2 = fork();
	if (pid2 == 0)
		second_child(pipex_vars->pipefd, pipex_vars->command2, pipex_vars->fd2,
			envp);
	ft_father_close(pipex_vars);
	free_struct(pipex_vars);
	return (ft_wait(pid, pid2));
}
