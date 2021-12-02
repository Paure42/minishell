/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:04:09 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:04:11 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		handle_double_quotes(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '\"' && str[i - 1] != '\\')
			return (i);
		i++;
	}
	return (-1);
}

int		handle_simple_quote(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '\'' && str[i - 1] != '\\')
			return (i);
		i++;
	}
	return (-1);
}

int		handle_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && (i == 0 || (str[i - 1] != '\\')))
			i = handle_double_quotes(str, i);
		else if (str[i] == '\'' && (i == 0 || (str[i - 1] != '\\')))
			i = handle_simple_quote(str, i);
		if (i == -1)
			return (-1);
		i++;
	}
	return (0);
}
