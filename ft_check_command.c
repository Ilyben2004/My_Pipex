#include "pipex.h"

static void	ft_free(char **paths)
{
	int	i;

	i = 0;
	while (paths && paths[i])
		free(paths[i++]);
	free(paths);
}
char	*ft_check_command(char **command, char **envp)
{
	int i;
	char *path;
	char *file;
	char **paths;

	if (!envp || !*envp)
		return (NULL);
	if (is_path(*command))
		return (*command);
	i = -1;
	paths = extract_paths(envp);
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		file = ft_strjoin(path, *command);
		free(path);
		if (access(file, X_OK)== 0)
		{
			free(*command);
			return (ft_free(paths), file);
		}
		free(file);
	}
	ft_free(paths);
	if (paths)
		printf("%s: command not found\n", *command);
	else 
		printf("%s: No such a file or a directory \n",*command);
	i = 0;
	while (command && command[i])
		free(command[i++]);
	return (NULL);
}
