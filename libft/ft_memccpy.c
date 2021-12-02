/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:02:23 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:03:35 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (0);
}
