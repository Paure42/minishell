/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:31:01 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:06:03 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	str = 0;
	i = ft_strlen(s);
	if (start >= i || !(str = malloc((len + 1) * sizeof(*str))))
		return (str = ft_calloc(1, sizeof(*str)));
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}
