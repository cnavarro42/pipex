/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:55:57 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/17 15:23:10 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_reader(int *fd, char **envp, char **argv)
{
	int	fd_outfile;
	char **command_splitted;
	char *path;

	
	command_splitted = ft_split(argv[3], ' ');
	path = pathing(command_splitted[0], envp);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	execve(path, command_splitted, envp);
}
