/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:54:23 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 09:54:25 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char		*check_s1_s2(char *s1, char *s2, int free_s2)
{
	char	*ret;

	if (!s1 && !s2)
		return (ft_calloc(1, 1));
	else if (!s1 && s2)
	{
		ret = ft_strdup(s2);
		if (free_s2)
			free(s2);
		return (ret);
	}
	else if (s1 && !s2)
	{
		ret = ft_strdup(s1);
		free(s1);
		return (ret);
	}
	else
		return (ft_calloc(1, 1));
}

char		*gnl_strjoin(char const *s1, char const *s2, int free_s2)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = -1;
	if (!s1 || !s2)
		return (check_s1_s2((char*)s1, (char*)s2, free_s2));
	i = gnl_ft_strlen(s1) + gnl_ft_strlen(s2);
	if (!(str = malloc((i + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++n])
	{
		str[i] = s2[n];
		i++;
	}
	str[i] = 0;
	free((char*)s1);
	if (free_s2 != 0)
		free((char*)s2);
	return (str);
}

char		*gnl_substr(char const *s, unsigned int start, size_t len, int f)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = NULL;
	i = gnl_ft_strlen(s);
	if (start >= i)
		return (free_strs((char*)s, str));
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (free_strs((char*)s, str));
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	if (f == 1)
		free((char*)s);
	return (str);
}

size_t		gnl_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
