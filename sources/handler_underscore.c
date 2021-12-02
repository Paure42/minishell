/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_underscore.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:56:53 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:56:54 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*fill_var_env(t_dir *dir_p, int i, int j)
{
	int		b;
	char	*underscore;

	b = 0;
	if (!(underscore = malloc((
		ft_strlen(dir_p->envp[i] + j) + 1) * sizeof(char))))
		return (NULL);
	while (dir_p->envp[i][j])
	{
		underscore[b] = dir_p->envp[i][j];
		j++;
		b++;
	}
	underscore[b] = 0;
	return (underscore);
}

char	*find_var_env(t_dir *dir_p, char *cmd, int i)
{
	int		j;
	int		b;

	j = 0;
	b = i;
	if (cmd[i] == 0 || ft_isspace(cmd[i]) == 1)
		return (ft_strdup("$"));
	while (cmd[i] && ft_isspace(cmd[i]) == 0 && (j = j + 1))
		i++;
	i = 0;
	while (dir_p->envp[i])
	{
		if (ft_strncmp(cmd + b, dir_p->envp[i], j) == 0
			&& (dir_p->envp[i][j] == '=' || dir_p->envp[i][j] == 0))
			break ;
		i++;
	}
	j++;
	if (dir_p->envp[i] == 0)
		return (find_command(cmd));
	else
		return (fill_var_env(dir_p, i, j));
}

char	*fill_underscore(char *cmd, int i, int j)
{
	char *underscore;

	if (!(underscore = malloc((ft_strlen(cmd + i) + 1) * sizeof(char))))
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '\\')
			i++;
		underscore[j] = cmd[i];
		if (cmd[i])
			i++;
		j++;
	}
	if (cmd[i] == 0)
		underscore[j] = 0;
	return (underscore);
}

char	*trim_underscore(t_dir *dir_p, char *cmd)
{
	int		i;
	int		j;

	i = ft_strlen(cmd) - 1;
	while (i > 0 && ft_isspace(cmd[i]) == 1)
		i--;
	while (i > 0 && ft_isspace(cmd[i]) == 0)
		i--;
	if (i >= 0 && ft_isspace(cmd[i]) == 1)
		i++;
	j = 0;
	if (i >= 0 && cmd[i] == '$')
	{
		if ((cmd[i + 1] != '_' ||
			(ft_isalnum(cmd[i + 2]) == 1 || cmd[i + 2] == '_')))
			return (find_var_env(dir_p, cmd, i + 1));
	}
	else if (i >= 0)
		return (fill_underscore(cmd, i, j));
	return (ft_calloc(1, 1));
}

void	update_underscore_env(t_dir *dir_p, char *cmd)
{
	char	*temp;
	char	*underscore;

	underscore = trim_underscore(dir_p, cmd);
	temp = ft_strjoin("export _=", underscore);
	if (ft_strlen(underscore) > 0)
		handler_export(dir_p, temp);
	if (underscore != NULL && underscore)
		free(underscore);
	free(temp);
}
