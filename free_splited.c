#include "pipex.h" 

void free_splited(char ** cmd1 , char ** cmd2) 
{
    int i;
    i = 0;
    while (cmd1[i])
    {
        free(cmd1[i++]);
    }
    i = 0;  
     while (cmd2[i])
    {
        free(cmd2[i++]);
    }
    free(cmd1);
    free(cmd2);  
}