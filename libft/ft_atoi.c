/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:30:00 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:02:15 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	p;

	n = 0;
	i = 0;
	p = 1;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		n = -n;
		p = -1;
	}
	else if (str[i] != '+')
		i--;
	while (str[++i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i] - '0');
	return (n * p);
}
