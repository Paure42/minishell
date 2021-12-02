/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:03:46 by paure             #+#    #+#             */
/*   Updated: 2020/12/21 09:03:48 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_whitespaces(char *str)
{
	int		i;
	char	*ret;

	i = ft_strlen(str) - 1;
	while (i > 0 && (ft_isspace(str[i]) == 1))
		i--;
	if (i > 0)
	{
		ret = ft_substr(str, 0, i + 1);
		free(str);
		return (ret);
	}
	return (str);
}
