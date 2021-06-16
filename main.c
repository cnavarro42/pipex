/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:19:28 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/16 17:57:36 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/pipex.h"

int	main(int argc, char **argv)
{
	int fd[2];
	pid_t pid;
	int status;
	int borrarcuandononecesite;

	borrarcuandononecesite = ft_strlen(argv[1]);
	if (argc < 1)
		return (-1);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_son(fd);
	else if (pid == -1)
	{
		/* ERROR */
		perror("Error");
		exit(-1);
	}
	ft_dad(fd, pid);
	
	wait(&status);
	wait(&status);

	return(0);
}
//printf("hola\n");