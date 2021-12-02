/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:02:03 by paure             #+#    #+#             */
/*   Updated: 2020/12/21 09:02:12 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/get_next_line.h"

int		ft_countline(int fd)
{
	int		nb;
	char	*line;

	line = NULL;
	nb = 0;
	if (fd < 0)
	{
		ft_putstr_fd("Wrong fd : ft_countline\n", 2);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		nb++;
		free(line);
	}
	free(line);
	return (nb);
}
