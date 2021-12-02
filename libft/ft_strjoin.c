/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:03:38 by paure             #+#    #+#             */
/*   Updated: 2020/12/21 09:03:39 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = -1;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return ((char*)s1);
	else if (!s1 && !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (i <= 0 || !(str = malloc((i + 1) * sizeof(*str))))
		return (str = ft_calloc(1, sizeof(*str)));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++n])
	{
		str[i] = s2[n];
		i++;
	}
	str[i] = 0;
	return (str);
}
