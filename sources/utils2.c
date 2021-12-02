/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:06:47 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 11:06:48 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_command(char *cmd)
{
	int		i;
	char	*underscore;

	underscore = NULL;
	i = 0;
	while (cmd[i] && ft_isspace(cmd[i]) == 0)
		i++;
	if (!(underscore = malloc((i + 1) * sizeof(char))))
		return (NULL);
	underscore[i] = 0;
	i--;
	while (i > -1)
	{
		underscore[i] = cmd[i];
		i--;
	}
	return (underscore);
}

int		new_strchr(char *str, char c, int i)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int		*fill_tab_spaces(int *tab_spaces, int i)
{
	int	*copy;
	int len;

	len = 0;
	while (tab_spaces[len])
		len++;
	if (!(copy = malloc((len + 2) * sizeof(int))))
		return (tab_spaces);
	len = 0;
	while (tab_spaces[len])
	{
		copy[len] = tab_spaces[len];
		len++;
	}
	copy[len] = i;
	len++;
	copy[len] = 0;
	len = 0;
	while (tab_spaces[len])
		len++;
	free(tab_spaces);
	return (copy);
}

int		skip_quotes_int(char *cmd, char c, int i)
{
	while (cmd[i])
	{
		if (cmd[i] == c)
		{
			if (i == 0 || (i > 0 && cmd[i - 1] != '\\'))
				return (i);
		}
		i++;
	}
	return (i);
}

int		skip_flag(char *cmd, int i, int *nl, char flag)
{
	int j;

	while (cmd[i])
	{
		if (cmd[i] == '-')
		{
			j = i;
			i++;
			while (cmd[i] && cmd[i] == flag)
				i++;
			if (ft_isspace(cmd[i]) == 0 && cmd[i] != 0)
			{
				write(1, cmd + j, i - j);
				break ;
			}
			else if (ft_isspace(cmd[i]) == 1 || cmd[i] == 0)
				*nl = 1;
		}
		else if (ft_isspace(cmd[i]) == 0)
			break ;
		if (cmd[i])
			i++;
	}
	return (i);
}
