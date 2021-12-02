/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:36:49 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:05:44 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (len == 0)
		len = 1;
	i = 0;
	if (!(str = ft_calloc((len + 1), sizeof(char))))
		return (0);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
