/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:22:18 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:22:20 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_env(t_dir *dir_p, char **envp)
{
	int	len;

	len = ft_strlen_2d(envp);
	if (!(dir_p->envp = malloc((len + 1) * sizeof(char*))))
		return ;
	len = 0;
	while (envp[len])
	{
		dir_p->envp[len] = ft_strdup(envp[len]);
		len++;
	}
	dir_p->envp[len] = 0;
}

void	handler_env(t_dir *dir_p)
{
	int		i;
	char	**env_spl;

	i = 0;
	env_spl = NULL;
	while (dir_p->envp[i])
	{
		env_spl = ft_split(dir_p->envp[i], '=');
		if (env_spl[1] && ft_strcmp(env_spl[1], "\'\'") != 0)
		{
			ft_putstr_fd(dir_p->envp[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
		ft_strdel_xy(env_spl);
	}
}
