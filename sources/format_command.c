/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:22:28 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:22:29 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		erase_quotes_copy(char *cmd, int i, char **ret, int *n)
{
	if ((cmd[i] == '\'' || cmd[i] == '\"') &&
		(i == 0 || cmd[i - 1] != '\\'))
	{
		if (i > *n)
			*ret = gnl_strjoin(*ret, ft_substr(cmd, *n, i - *n), 2);
		*ret = gnl_strjoin(*ret, skip_quotes(cmd + i + 1, cmd[i]), 2);
		i = skip_quotes_int(cmd, cmd[i], i + 1);
		*n = i;
	}
	else if (cmd[i] == '\\')
	{
		*ret = gnl_strjoin(*ret, ft_substr(cmd, *n, i - *n), 2);
		i++;
		if (cmd[i] != 0)
			*n = i + 1;
		else
			*n = i;
		*ret = gnl_strjoin(*ret, ft_substr(cmd, i, 1), 2);
		return (i + 1);
	}
	return (i - 1);
}

char	*erase_quotes_error(char *ret, char c, t_dir *dir_p)
{
	if (ret != 0)
		free(ret);
	ft_putstr_fd("export: ", 2);
	write(2, &c, 1);
	ft_putstr_fd(" not a valid identifier\n", 2);
	dir_p->ret_last = 1;
	return (0);
}

char	*erase_quotes(char *cmd, t_dir *dir_p)
{
	int		i;
	char	*ret;
	int		n;
	int		arg;

	i = 0;
	n = 0;
	ret = 0;
	arg = 0;
	while (i <= (int)ft_strlen(cmd))
	{
		if ((cmd[i] == '\'' || cmd[i] == '\"') || (cmd[i] == '\\'
			&& arg == 1))
			i = erase_quotes_copy(cmd, i, &ret, &n);
		else if (cmd[i] == '\\' || (cmd[i] == '-' && arg == 0)
			|| (cmd[i] == '+' && cmd[i + 1] != '=' && arg == 0))
			return (erase_quotes_error(ret, cmd[i], dir_p));
		else if (cmd[i] == '=')
			arg = 1;
		i++;
	}
	if (cmd[n] == '\"' || cmd[n] == '\'')
		return (gnl_strjoin(ret, ft_substr(cmd, n, i - n - 1), 2));
	else
		return (gnl_strjoin(ret, ft_substr(cmd, n, i - n), 2));
}

int		format_command2(char *cmd, int i, char **ret)
{
	int j;

	j = i;
	if (cmd[i] == '\\')
	{
		*ret = gnl_strjoin(*ret, ft_substr(cmd, i + 1, 1), 2);
		i++;
	}
	else if (ft_isprint(cmd[i]) == 1)
	{
		while (ft_isprint(cmd[i]) == 1 && ft_isspace(cmd[i]) == 0 &&
			cmd[i] != '>' && cmd[i] != '<' && cmd[i] != '\\')
			i++;
		*ret = gnl_strjoin(*ret, ft_substr(cmd, j, i - j), 2);
		if (cmd[i] != '\'' && cmd[i] != '\"' && cmd[i] != '\\')
			*ret = gnl_strjoin(*ret, " ", 0);
		while (cmd[i] && ft_isspace(cmd[i]) == 1)
			i++;
		return (i);
	}
	if (cmd[i] != 0)
		return (i + 1);
	return (i);
}

char	*format_command(char *cmd, t_dir *p)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if ((cmd[i] == '<' || cmd[i] == '>') && (i == 0 || cmd[i - 1] != '\\'))
			i = skip_filename(cmd, i + 1);
		else if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			ret = gnl_strjoin(ret, skip_quotes(cmd + i + 1, cmd[i]), 2);
			i = new_strchr(cmd, cmd[i], i + 1);
			p->tab_spaces = fill_tab_spaces(p->tab_spaces, ft_strlen(ret));
			if (cmd[i])
				i++;
		}
		else
			i = format_command2(cmd, i, &ret);
	}
	return (ret);
}
