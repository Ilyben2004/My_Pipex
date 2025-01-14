#include "pipex.h"

void	free_splited(char **cmd1, char **cmd2)
{
	int	i;

	i = 0;
	if (cmd1)
	{
		while (cmd1[i])
			free(cmd1[i++]);
		free(cmd1);
	}
	i = 0;
	if (cmd2)
	{
		while (cmd2[i])
			free(cmd2[i++]);
		free(cmd2);
	}
}
