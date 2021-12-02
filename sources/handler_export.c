/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:26:41 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:26:42 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		join_env(t_dir *dir_p, char **checker, char **checking, int pos)
{
	char	**rmadd;

	rmadd = ft_split(checker[0], '+');
	if (ft_strcmp(rmadd[0], checking[0]) == 0)
	{
		if (ft_strchr(dir_p->envp[pos], '=') == 0)
		{
			dir_p->envp[pos] = ft_strjoin(checking[0], "=");
			dir_p->envp[pos] = gnl_strjoin(dir_p->envp[pos], checker[1], 0);
			ft_strdel_xy(rmadd);
			return (1);
		}
		dir_p->envp[pos] = gnl_strjoin(dir_p->envp[pos], checker[1], 0);
		ft_strdel_xy(rmadd);
		return (1);
	}
	ft_strdel_xy(rmadd);
	return (0);
}

void	add_env(char *variable, t_dir *dir_p)
{
	int		i;
	char	**checker;
	char	**checking;
	int		edit;

	edit = 0;
	i = 0;
	checker = ft_split(variable, '=');
	while (dir_p->envp[i] && edit == 0)
	{
		checking = ft_split(dir_p->envp[i], '=');
		if (checker[0][ft_strlen(checker[0]) - 1] == '+')
			edit = join_env(dir_p, checker, checking, i);
		else if (ft_strcmp(checker[0], checking[0]) == 0 && (edit = -1) == -1)
		{
			edit_var_env(i, dir_p, variable);
			ft_strdel_xy(checking);
			break ;
		}
		ft_strdel_xy(checking);
		i++;
	}
	if (edit == 0)
		add_var_env(dir_p, variable);
	ft_strdel_xy(checker);
}

void	export_env(char *variable, t_dir *dir_p)
{
	if (variable != 0 &&
		(ft_isalpha(variable[0]) == 1 || variable[0] == '_'))
		add_env(variable, dir_p);
	else
		errno = 1;
	ft_strdel(variable);
}

void	aff_export(t_dir *dir_p)
{
	int		i;
	char	**env_spl;

	i = 0;
	env_spl = NULL;
	while (dir_p->envp[i])
	{
		env_spl = ft_split(dir_p->envp[i], '=');
		ft_putstr_fd("declare -x ", 1);
		if (env_spl[1] && ft_strcmp(env_spl[1], "") == 0)
		{
			ft_putstr_fd(env_spl[0], 1);
			ft_putstr_fd("\n", 1);
		}
		else
		{
			ft_putstr_fd(dir_p->envp[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
		ft_strdel_xy(env_spl);
	}
}

void	handler_export(t_dir *dir_p, char *old_cmd)
{
	int		i;
	char	*tmp;
	char	**l_split;

	tmp = var_string(old_cmd, dir_p);
	l_split = ft_split(tmp, ' ');
	i = ft_strlen_2d(l_split);
	if (i == 1)
		aff_export(dir_p);
	else if (i >= 2 && (i = 0) == 0)
		while (l_split[++i])
			export_env(erase_quotes(l_split[i], dir_p), dir_p);
	else
		errno = 7;
	ft_strdel_xy(l_split);
	if (tmp != old_cmd)
		ft_strdel(tmp);
}
