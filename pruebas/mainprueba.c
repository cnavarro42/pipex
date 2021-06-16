/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:37:18 by cnavarro          #+#    #+#             */
/*   Updated: 2021/06/14 17:28:47 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		read_value;
	char	buf[2];
	char	*file1;

	if (argc < 1)
		printf("no arguments");
	fd = open(argv[1], O_RDONLY);
	read_value = read(fd, buf, 1);
	file1 = ft_calloc(sizeof(char), 1);
	while (read_value > 0)
	{
		file1 = ft_strjoinchar(file1, buf[0]);
		read_value = read(fd, buf, 1);
		
	}
	printf("%s\n", file1);
	return (0);
	system("ls -l infile.txt");
}
//printf("hola\n");
//printf("%c\n", buf[0]);