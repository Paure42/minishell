/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:04:37 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:04:38 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_arrow(char *cmd, int i)
{
	char	*filename;
	int		fd_file;

	if ((filename = find_filename(cmd + i + 1)) != 0)
	{
		fd_file = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0666);
		dup2(fd_file, STDOUT_FILENO);
		free(filename);
	}
}

int		handle_double_arrow(char *cmd, int i)
{
	char	*filename;
	int		fd_file;

	if ((filename = find_filename(cmd + i + 2)) != 0)
	{
		fd_file = open(filename, O_CREAT | O_APPEND | O_RDWR, 0666);
		dup2(fd_file, STDOUT_FILENO);
		free(filename);
	}
	return (i + 1);
}

void	handle_reverse_arrow(char *cmd, int i)
{
	char	*filename;
	int		fd_file;

	if ((filename = find_filename(cmd + i + 1)) != 0)
	{
		fd_file = open(filename, O_RDONLY);
		if (fd_file > 0)
			dup2(fd_file, STDIN_FILENO);
		free(filename);
	}
}

char	*handle_redirect(char *c, t_dir *p)
{
	int		i;
	char	q;

	i = 0;
	while (c[i] && errno == 0)
	{
		if ((c[i] == '\'' || c[i] == '\"') && (i == 0 || c[i - 1] != '\\'))
		{
			q = c[i];
			i++;
			while (c[i] && c[i] != q)
				i++;
		}
		if ((c[i] == '>' && c[i + 1] != '>') && (i == 0 || c[i - 1] != '\\'))
			handle_arrow(c, i);
		if ((c[i] == '>' && c[i + 1] == '>') && (i == 0 || c[i - 1] != '\\'))
			i = handle_double_arrow(c, i);
		else if ((c[i] == '<') && (i == 0 || c[i - 1] != '\\'))
			handle_reverse_arrow(c, i);
		if (c[i])
			i++;
	}
	return (format_command(c, p));
}
