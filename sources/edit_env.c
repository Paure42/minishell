/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:06:37 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:01:52 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	del_var_env(t_dir *dir_p, int pos)
{
	char	**temp;
	int		i;
	int		j;

	i = ft_strlen_2d(dir_p->envp);
	j = 0;
	if (!(temp = malloc(sizeof(char*) * (i))))
		return ;
	i = 0;
	while (dir_p->envp[j])
	{
		if (j != pos)
		{
			temp[i] = ft_strdup(dir_p->envp[j]);
			i++;
		}
		j++;
	}
	ft_strdel_xy(dir_p->envp);
	temp[i] = 0;
	dir_p->envp = temp;
}

void	edit_null(int pos, t_dir *dir_p, char *variable)
{
	char *null;

	null = ft_strdup("");
	if (ft_strchr(variable, '=') == 0)
	{
		free(null);
		null = ft_strdup("=");
	}
	free(dir_p->envp[pos]);
	dir_p->envp[pos] = ft_strjoin(variable, null);
	free(null);
}

void	edit_var_env(int pos, t_dir *dir_p, char *variable)
{
	int		i;

	i = ft_strlen(variable);
	if ((i > 0 && variable[i - 1] == '=' && variable[i] == '\0')
	|| ft_strchr(variable, '=') == 0)
		edit_null(pos, dir_p, variable);
	else
	{
		free(dir_p->envp[pos]);
		dir_p->envp[pos] = ft_strjoin("", variable);
	}
}

void	add_var_env(t_dir *dir_p, char *variable)
{
	char	**temp;
	int		i;
	int		pos;

	pos = ft_strlen_2d(dir_p->envp);
	if (!(temp = malloc(sizeof(char*) * (pos + 2))))
		return ;
	i = 0;
	while (dir_p->envp[i])
	{
		temp[i] = ft_strdup(dir_p->envp[i]);
		i++;
	}
	i = ft_strlen(variable);
	if ((i > 0 && variable[i - 1] == '=' && variable[i] == '\0')
	|| ft_strchr(variable, '=') == 0)
		if (ft_strchr(variable, '=') == 0)
			temp[pos] = ft_strjoin(variable, "");
		else
			temp[pos] = ft_strjoin(variable, "");
	else
		temp[pos] = ft_strdup(variable);
	temp[pos + 1] = 0;
	ft_strdel_xy(dir_p->envp);
	dir_p->envp = temp;
}
