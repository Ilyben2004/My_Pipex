#include <stdio.h>
#include <unistd.h>

int  main(void) {
    char *argv[] = {"ls", "-l", "/tmp", NULL};

    execve("/bin/ls", argv, NULL); 
    // Or  "/usr/bin/ls", depending where  
    //    is stored 'ls' on your system

    // On success theses lines are not reached
    perror("execve failed");

    return 0;
}