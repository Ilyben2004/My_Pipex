#include "pipex.h"


static void ft_free( char ** paths )
{
    int i;

    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
}
char *ft_check_command(char *command , char **envp)
{
    int i;
    char * path;
    char *file;
    char ** paths;
    int ret;

    i = 0;
    if (is_path(command))
        return (command);
    paths = extract_paths (envp);
    while (paths[i])
    {
        path = ft_strjoin (paths[i] , "/");
        file = ft_strjoin(path,command);
        free(path);
        ret = access(file , X_OK);
        if (ret == 0)
            return (ft_free(paths), file);
        free(file);
        i++;
    }
    ft_free(paths);
    printf("%s: command not found\n",command);
 
    return (NULL);
}