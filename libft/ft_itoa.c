/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:53:59 by paure             #+#    #+#             */
/*   Updated: 2020/03/10 19:03:07 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		k;
	int		negatif;

	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	k = ft_countnumbers(n) + 1;
	if (!(str = ft_calloc(k, sizeof(*str))))
		return (str = ft_calloc(1, sizeof(*str)));
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		negatif = 0;
	}
	else
		negatif = -1;
	k--;
	while (--k > negatif)
	{
		str[k] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
