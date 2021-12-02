/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:05:40 by paure             #+#    #+#             */
/*   Updated: 2020/12/21 09:05:41 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_double(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

char	**ft_double_array_sort(char **array)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	j = 0;
	len = ft_strlen_double(array);
	temp = NULL;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[j][0] > array[i][0])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
