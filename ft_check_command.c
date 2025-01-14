/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:59:58 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:00 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*check_paths(char **paths, char **command)
{
	int		i;
	char	*path;
	char	*file;

	i = -1;
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		file = ft_strjoin(path, *command);
		free(path);
		if (access(file, X_OK) == 0)
			return (file);
		free(file);
	}
	return (NULL);
}

static void	free_command(char **command)
{
	int	i;

	i = 0;
	while (command[i])
		free(command[i++]);
}

char	*ft_check_command(char **command, char **envp)
{
	char	**paths;
	char	*file;

	if (!command)
		return (NULL);
	if (is_path(*command))
		return (*command);
	paths = extract_paths(envp);
	if (!paths)
		return (ft_put_two_strs(NOFILE, *command), NULL);
	file = check_paths(paths, command);
	if (file)
	{
		free(*command);
		return (free_splited(&paths, NULL), file);
	}
	ft_put_two_strs(NOCOMMAND, *command);
	free_command(command);
	return (free_splited(&paths, NULL), NULL);
}
