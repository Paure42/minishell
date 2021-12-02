/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countletters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:56:35 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 09:56:36 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countletters(char const *s, char c, int start)
{
	int	nbchar;
	int	j;

	nbchar = 0;
	while (s && s[start])
	{
		if (s[start] == c && (start == 0 || s[start - 1] != '\\'))
			break ;
		if ((s[start] == '\'' || s[start] == '\"') &&
			(start == 0 || s[start - 1] != '\\'))
		{
			j = start;
			start++;
			nbchar++;
			while (s[start] && s[start] != s[j])
			{
				start++;
				nbchar++;
			}
		}
		if (s[start] && (nbchar = nbchar + 1))
			start++;
	}
	return (nbchar);
}
