/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:36:40 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/17 12:11:22 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_dad(int *fd, pid_t pid, char **envp, char **argv)
{
	close(fd[WRITE_END]);
	pid = fork();
	if (pid == 0)
		ft_reader(fd, envp, argv);
	else if (pid == -1)
	{
		perror("Error");
		exit(-1);
	}
	else
		close(fd[READ_END]);
}
