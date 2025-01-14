/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <ibennaje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:33:39 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/12 10:58:38 by ibennaje         ###   ########.fr       */
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
	int	status;

	waitpid(pid, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (EXIT_FAILURE);
}

void	ft_father_close(pipex_t *pipex_vars)
{
	close(pipex_vars->fd);
	close(pipex_vars->fd2);
	close(pipex_vars->pipefd[0]);
	close(pipex_vars->pipefd[1]);
}
