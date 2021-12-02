/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:41:09 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:02:29 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmpchar(char const *s1, char const *set, int start, int pos)
{
	int i;

	i = -1;
	if (!(s1) || !(set))
		return (0);
	while (set[++i] && start != -1 && s1[start])
	{
		if (set[i] == s1[start])
		{
			start += pos;
			i = -1;
		}
	}
	return (start);
}
