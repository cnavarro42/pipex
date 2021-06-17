/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:36:40 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/17 17:01:22 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_writer(int *fd, char **envp, char **argv)
{
	int	fd_infile;
	char **command_splitted;
	char *path;

	command_splitted = ft_split(argv[2], ' ');
	path = pathing(command_splitted[0], envp);
	close(fd[READ_END]);
	fd_infile = open(argv[1], O_RDONLY);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execve(path, command_splitted, envp);
}
