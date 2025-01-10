#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
    execl("/bin/lls","lls",NULL);
    perror("");
    return 0;
}