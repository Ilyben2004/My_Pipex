#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include "pipex.h"
#include <errno.h>
# define RED "\033[31m"

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BOLD "\033[1m"
# define RESET "\033[0m"



int main( int argc, char *argv[], char *envp[] )
{
	char *command[] = {"ls", ">", "outfile",NULL};
	execve("/bin/ls",command,NULL);

}
