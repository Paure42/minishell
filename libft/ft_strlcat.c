/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:30:28 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:05:29 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;
	size_t j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (dest_len >= size || size == 0)
		return (src_len + size);
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = 0;
	return (dest_len + src_len);
}
