/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:39 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:47 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		higheroverlap;
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (src == dst)
		return ((void *)src);
	higheroverlap = dst > src;
	while (len > 0)
	{
		if (higheroverlap)
			*((unsigned char *)dst + len - 1) = *((unsigned char *)src + len
					- 1);
		else
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
		len--;
	}
	return (dst);
}

int	ft_wait(int pid, int pid2)
{
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (EXIT_SUCCESS);
}

void	ft_father_close(t_pipex *pipex_vars)
{
	if (pipex_vars->fd != -1)
		close(pipex_vars->fd);
	if (pipex_vars->fd2 != -1)
		close(pipex_vars->fd2);
	close(pipex_vars->pipefd[0]);
	close(pipex_vars->pipefd[1]);
}

void	ft_put_two_strs(char *str1, char *str2)
{
	write(1, str2, ft_strlen(str2));
	write(1, str1, ft_strlen(str1));
}

void	free_splited(char ***cmd1, char ***cmd2)
{
	int	i;

	if (cmd1 && *cmd1)
	{
		i = -1;
		while ((*cmd1)[++i])
		{
			free((*cmd1)[i]);
			(*cmd1)[i] = NULL;
		}
		free(*cmd1);
		*cmd1 = NULL;
	}
	if (cmd2 && *cmd2)
	{
		i = -1;
		while ((*cmd2)[++i])
		{
			free((*cmd2)[i]);
			(*cmd2)[i] = NULL;
		}
		free(*cmd2);
		*cmd2 = NULL;
	}
}
