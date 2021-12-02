/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 03:56:11 by elaignel          #+#    #+#             */
/*   Updated: 2020/12/22 13:16:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_xy(char **str)
{
	int		x;

	x = 0;
	if (str)
		while (str[x] != NULL)
		{
			if (str[x])
				free(str[x]);
			str[x] = NULL;
			x++;
		}
	if (str[x])
		free(str[x]);
	if (str)
		free(str);
}
