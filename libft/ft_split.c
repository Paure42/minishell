/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:02:52 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:02:54 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		k;
	char	**tab;
	int		i;
	int		j;
	int		nbchar;

	i = 0;
	j = 0;
	if (!s || !s[0] || (!(k = ft_countwords(s, c)))
			|| !(tab = ft_calloc((k + 1), sizeof(char*))))
		return (tab = ft_calloc(1, sizeof(char*)));
	while (--k > -1)
	{
		if (s[i] != c)
		{
			i += nbchar = ft_countletters(s, c, i);
			if (!(tab[j] = ft_substr(s, i - nbchar, nbchar)))
				return (free_tab(tab));
			j++;
		}
		while (s[i] == c)
			i++;
	}
	return (tab);
}
