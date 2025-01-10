#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
int main(void)
{ pid_t pid;
pid = fork();
if (pid == 0)
{ printf("child\n");
return (0);
}
wait(NULL);
printf("parent\n");
return 0;
}