/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:07:25 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:07:27 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		find_filename_backslash(char *cmd, int start, int end, char **filename)
{
	while (cmd[end])
	{
		if ((ft_isprint(cmd[end]) == 0 || ft_isspace(cmd[end]) == 1 ||
			cmd[end] == '<' || cmd[end] == '>') &&
			(end == 0 || cmd[end - 1] != '\\'))
			break ;
		if (cmd[end] == '\\')
		{
			*filename = gnl_strjoin(*filename,
				ft_substr(cmd, start, end - start), 2);
			end++;
			start = end;
		}
		end++;
	}
	*filename = gnl_strjoin(*filename, ft_substr(cmd, start, end - start), 2);
	return (end);
}

char	*find_filename(char *cmd)
{
	int		start;
	int		end;
	char	*filename;

	end = 0;
	filename = 0;
	while (cmd[end])
	{
		while (cmd[end] && ft_isspace(cmd[end]) == 1)
			end++;
		start = end;
		if ((cmd[end] == '\"' || cmd[end] == '\'')
			&& (end == 0 || cmd[end - 1] != '\\'))
		{
			end += gnl_strchr(cmd + end + 1, cmd[start]) + 1;
			filename = gnl_strjoin(filename,
				skip_quotes(cmd + start + 1, cmd[start]), 2);
		}
		else if (ft_isprint(cmd[end]) == 1)
			end = find_filename_backslash(cmd, start, end, &filename);
		if ((cmd[end] == '>' || cmd[end] == '<' || ft_isspace(cmd[end]) == 1)
			&& (end == 0 || cmd[end - 1] != '\\'))
			break ;
	}
	return (filename);
}

int		skip_filename(char *cmd, int j)
{
	char	c;

	if (cmd[j] == '>')
		j++;
	while (ft_isspace(cmd[j]) == 1)
		j++;
	while (cmd[j])
	{
		if ((cmd[j] == '\'' || cmd[j] == '\"')
			&& (j == 0 || cmd[j - 1] != '\\'))
		{
			c = cmd[j];
			while (cmd[j] != c && (j == 0 || cmd[j - 1] != '\\'))
				j++;
		}
		else if ((cmd[j] == '>' || cmd[j] == '<' || ft_isspace(cmd[j]) == 1)
			&& (j == 0 || cmd[j - 1] != '\\'))
			return (j);
		j++;
	}
	return (j);
}
