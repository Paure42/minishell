/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:45:09 by elaignel          #+#    #+#             */
/*   Updated: 2020/03/10 19:04:52 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(char **all, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(all[i]);
		i++;
	}
}

int		checksep(char ccheck, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (ccheck == charset[i])
			return (1);
		i++;
	}
	if (ccheck == '\0')
		return (1);
	return (0);
}

int		nb_mots(char *str, char *charset)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (checksep(str[i + 1], charset) == 1
				&& checksep(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_print_split(char **all, char *str, char *charset)
{
	int i;
	int j;
	int x;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (checksep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (checksep(str[i + j], charset) == 0)
				j++;
			if ((all[x++] = ft_substr(str, i, j + 1)) == NULL)
			{
				ft_free_all(all, x);
				return (0);
			}
			i = i + j;
		}
	}
	return (all);
}

char	**ft_splitstr(char *str, char *charset)
{
	char **all;

	if (!str || !(all = malloc(sizeof(char *) * (nb_mots(str, charset) + 1))))
		return (0);
	if ((all = ft_print_split(all, str, charset)))
		return (all);
	else
	{
		free(all);
		return (0);
	}
}
