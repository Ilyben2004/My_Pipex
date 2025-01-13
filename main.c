#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include "pipex.h"
#include <errno.h>

int main( int argc, char *argv[], char *envp[] )
{
	int fd  = open ("infile",O_RDWR);
	pid_t pid = fork();
	char buffer[100];
	dup2(fd,19);
	close(19);
	read (fd , buffer , 3);
	printf("%s",buffer);

}
