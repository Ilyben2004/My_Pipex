#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include "pipex.h"

int main( int argc, char *argv[], char *envp[] )
{
    char *check = ft_check_command("ldcdcdcs" , envp);
    printf("%s" , check);
    free(check);
    return 0;
}