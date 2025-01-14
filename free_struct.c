#include "pipex.h"

void	free_struct(pipex_t *pipex)
{
	free_splited(pipex->command1, pipex->command2);
	free(pipex);
}
