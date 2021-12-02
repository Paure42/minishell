/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:34:04 by elaignel          #+#    #+#             */
/*   Updated: 2021/01/21 12:34:04 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_unset(t_dir *dir_p, char *variable)
{
	int		i;
	char	**var_split;

	i = 0;
	var_split = NULL;
	while (dir_p->envp[i])
	{
		var_split = ft_split(dir_p->envp[i], '=');
		if (ft_strcmp(var_split[0], variable) == 0)
		{
			del_var_env(dir_p, i);
			ft_strdel_xy(var_split);
			return ;
		}
		ft_strdel_xy(var_split);
		i++;
	}
}

void	handler_unset(t_dir *dir_p, char *cmd)
{
	int		i;
	char	**l_split;

	i = 0;
	dir_p->pipe = 1;
	l_split = ft_split(cmd, ' ');
	while (l_split[i])
		i++;
	if (ft_strcmp(l_split[0], "unset") == 0 && i > 1)
	{
		i = 1;
		while (l_split[i] != 0)
		{
			check_unset(dir_p, l_split[i]);
			i++;
		}
	}
	if (l_split)
		ft_strdel_xy(l_split);
}
