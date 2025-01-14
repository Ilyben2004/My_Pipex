#include "pipex.h"

char	*ft_check_command(char **command, char **envp)
{
	int		i;
	char	*path;
	char	*file;
	char	**paths;

	if (is_path(*command))
		return (*command);
	i = -1;
	paths = extract_paths(envp);
	if (!paths)
		return (printf(NOFILE, *command), NULL);
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		file = ft_strjoin(path, *command);
		free(path);
		if (access(file, X_OK) == 0)
		{
			free(*command);
			return (free_splited(paths, NULL), file);
		}
		free(file);
	}
	printf(NOCOMMAND, *command);
	return (free_splited(paths, command), NULL);
}
