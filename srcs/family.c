/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:36:40 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/18 19:00:29 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_writer(int *fd, char **envp, char **argv)
{
	int		fd_infile;
	char	**command_splitted;
	char	*path;
	int		i;

	i = -1;
	command_splitted = ft_split(argv[2], ' ');
	path = pathing(command_splitted[0], envp);
	if (!path)
	{
		perror("Error: Invalid command");
		exit(-1);
	}
	close(fd[READ_END]);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
	{
		perror("Error: Infile not openned");
		exit(-1);
	}
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execve(path, command_splitted, envp);
}

void	ft_reader(int *fd, char **envp, char **argv)
{
	int		fd_outfile;
	char	**command_splitted;
	char	*path;

	command_splitted = ft_split(argv[3], ' ');
	path = pathing(command_splitted[0], envp);
	if (!path)
	{
		perror("Error: Invalid command");
		exit(-1);
	}
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC
			| O_APPEND, S_IRWXU);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	execve(path, command_splitted, envp);
}

void	ft_dad(int *fd, pid_t pid, char **envp, char **argv)
{
	close(fd[WRITE_END]);
	pid = fork();
	if (pid == 0)
		ft_reader(fd, envp, argv);
	else if (pid == -1)
	{
		perror("Error: Son not found");
		exit(-1);
	}
	else
		close(fd[READ_END]);
}
