/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:54:50 by cnavarro          #+#    #+#             */
/*   Updated: 2021/04/07 11:52:40 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*mdst;
	const unsigned char	*msrc;

	mdst = (unsigned char *)dst;
	msrc = (const unsigned char *)src;
	if (n)
	{
		while (n-- != 0)
		{
			*mdst++ = *msrc++;
			if (*mdst == (unsigned char)c)
				return (mdst);
		}
	}
	return (NULL);
}
