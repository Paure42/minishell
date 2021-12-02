/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:10 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:04:00 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		string[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
