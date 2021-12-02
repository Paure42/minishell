/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:02:30 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:02:34 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_quotes(const char *s, int i, int *j)
{
	if (((s[i] == '\"' || s[i] == '\'') &&
			(i == 0 || s[i - 1] != '\\')) && (*j = i))
		return (1);
	else
		return (0);
}

int				ft_countwords(char const *s, char c)
{
	int i;
	int j;
	int nbwords;

	i = 0;
	nbwords = 1;
	while (s && s[i])
	{
		if (s[i] == c && (i == 0 || s[i - 1] != '\\'))
		{
			while (s[i + 1] == c)
				i++;
			nbwords = (s[i + 1] != 0) ? nbwords + 1 : nbwords;
		}
		else if (check_quotes(s, i, &j) == 1)
		{
			i++;
			while (s[i] && s[i] != s[j])
				i++;
		}
		i = (s[i] != 0) ? i + 1 : i;
	}
	if (nbwords == 1 && s[0] == c)
		return (0);
	return (nbwords);
}
