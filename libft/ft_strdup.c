/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:46:48 by cnavarro          #+#    #+#             */
/*   Updated: 2021/04/07 10:53:15 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *cad)
{
	char	*new;
	int		len;

	len = 0;
	len = ft_strlen(cad);
	new = malloc(sizeof(char) * (len + 1));
	if (!(new))
		return (NULL);
	len = 0;
	while (cad[len])
	{
		new[len] = cad[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
