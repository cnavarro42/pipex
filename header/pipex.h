#ifndef PIPEX_H
# define PIPEX_H
# define READ_END	0
# define WRITE_END	1
# define FILE_NAME	"outfile.txt"

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void	    ft_dad(int *fd, pid_t pid, char **envp, char **argv);
void		ft_writer(int *fd, char **envp, char **argv);
void        ft_reader(int *fd, char **envp, char **argv);
void        check_argv(int argc);
char        *pathing(char *command, char **envp);

#endif