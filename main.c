/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:19:28 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/21 16:34:08 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	check_argv(argc);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_writer(fd, envp, argv);
	else if (pid == -1)
	{
		perror("Error: Son not found");
		exit(-1);
	}
	ft_dad(fd, pid, envp, argv);
	wait(&status);
	wait(&status);
	return (0);
}

void	check_argv(int argc)
{
	if (argc != 5)
	{
		perror("No valids arguments");
		exit(-1);
	}
}
