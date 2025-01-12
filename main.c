#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include "pipex.h"
#include <errno.h>

int main( int argc, char *argv[], char *envp[] )
{
    int fd = open("filen",O_WRONLY);
    printf("%d",errno);
    return 0;
}