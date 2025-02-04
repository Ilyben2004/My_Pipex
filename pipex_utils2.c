/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:00:33 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:34 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**extract_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ":"));
		i++;
	}
	return (NULL);
}

int	is_path(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i++] == '/')
			return (1);
	}
	return (0);
}

void	first_child(int *pipefd, char **command1, int fd, char **envp)
{
	if (command1 && command1[0])
	{
		close(pipefd[0]);
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		close(fd);
		close(pipefd[1]);
		execve(command1[0], command1, envp);
		perror(command1[0]);
	}
	exit(0);
}

void	second_child(int *pipefd, char **command2, int fd2, char **envp)
{
	if (command2 && command2[0])
	{
		command2[0] = ft_check_command(command2, envp);
		if (command2[0])
		{
			close(pipefd[1]);
			dup2(fd2, 1);
			dup2(pipefd[0], 0);
			close(fd2);
			close(pipefd[0]);
			execve(command2[0], command2, envp);
			perror(command2[0]);
		}
	}
	exit(0);
}

void	free_struct(t_pipex *pipex)
{
	free_splited((&pipex->command1), &pipex->command2);
	free(pipex);
}
