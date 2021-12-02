/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:54:10 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:06:00 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		begin;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	begin = ft_cmpchar(s1, set, 0, 1);
	end = ft_cmpchar(s1, set, len - 1, -1);
	if (begin == len || !(str = ft_substr(s1, begin, end + 1 - begin)))
		return (0);
	free((char*)s1);
	return (str);
}
