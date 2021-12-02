/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:31:32 by elaignel          #+#    #+#             */
/*   Updated: 2020/03/10 19:05:19 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strdup_double(char **s)
{
	int		i;
	int		j;
	char	**dup;

	j = 0;
	i = 0;
	dup = NULL;
	while (s[j])
		j++;
	dup = malloc(sizeof(char*) * (j));
	while (s[i])
	{
		dup[i] = ft_strdup(s[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
