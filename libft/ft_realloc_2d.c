/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:03:05 by paure             #+#    #+#             */
/*   Updated: 2020/12/21 09:03:06 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strealloc_2d_dlt(char **src, size_t dlt)
{
	char	**dest;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen_2d(src);
	if (!(dest = (char **)malloc(sizeof(char *) * (len - 1))))
		return (0);
	while (j < len)
	{
		if (j != (int)dlt)
		{
			dest[i] = ft_strdup(src[j]);
			i++;
		}
		j++;
	}
	dest[i] = 0;
	return (dest);
}
