/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:25:29 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:03:57 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
		return (dest);
	}
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
