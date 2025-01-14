/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibennaje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:00:19 by ibennaje          #+#    #+#             */
/*   Updated: 2025/01/14 23:00:26 by ibennaje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define NOFILE ": No such a file or a directory\n"
# define NOCOMMAND ": Command not found\n"

typedef struct pipex_s
{
	int		fd;
	int		fd2;
	int		pipefd[2];
	char	**command1;
	char	**command2;

}			t_pipex;

char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char *c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlen(const char *s);
void		free_splited(char ***cmd1, char ***cmd2);
void		first_child(int *pipefd, char **command1, int fd, char **envp);
void		second_child(int *pipefd, char **command2, int fd, char **envp);
int			is_path(char *command);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		**extract_paths(char **envp);
char		*ft_check_command(char **command, char **envp);
int			ft_wait(pid_t pid, pid_t pid2);
void		ft_father_close(t_pipex *pipex_vars);
void		free_struct(t_pipex *pipex);
void		ft_put_two_strs(char *str1, char *str2);
#endif
