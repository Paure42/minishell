/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:14 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:04:38 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long int i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + '0', fd);
	}
	if (i < 10)
		ft_putchar_fd(i % 10 + '0', fd);
}
