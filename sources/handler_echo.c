/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:35:05 by elaignel          #+#    #+#             */
/*   Updated: 2021/01/21 12:35:05 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			echo_underscore(char *env, int i, int b)
{
	int	len;

	if (env[1] == '=')
	{
		env = env + 2;
		len = ft_strlen(env);
		while (len > 0 && ft_isspace(env[len]) == 0)
		{
			if (env[len] == '/')
			{
				while (len > 0 && env[len] == '/')
					len--;
				break ;
			}
			len--;
		}
		if (env[len] != '\'' && env[len + 1] != '\'')
			write(1, env + len, ft_strlen(env + len));
	}
	else
		write(1, env + i - b + 1, ft_strlen(env + i - b + 1));
}

int				echo_dollar(char **env, char *cmd, int i, char quote)
{
	int j;
	int b;

	j = -1;
	b = i;
	while (cmd[i] && (ft_isalnum(cmd[i]) == 1 || cmd[i] == '_'))
		i++;
	while (env[++j])
	{
		if (ft_strncmp(cmd + b, env[j], i - b) == 0
			&& (env[j][i - b] == '=' || env[j][i - b] == '\0'))
		{
			if ((quote == '\0' || quote == '\"') && env[j][0] == '_')
				echo_underscore(env[j], i, b);
			else if (quote == '\0' || quote == '\"')
				write(1, env[j] + i - b + 1, ft_strlen(env[j] + i - b + 1));
			else if (quote == '\'')
			{
				write(1, "$", 1);
				write(1, env[j], i - b);
			}
		}
	}
	i = (quote == '\0') ? i - 1 : i;
	return (i);
}

int				echo_quotes(t_dir *dir_p, char *cmd, int i, char quote)
{
	char	*to_print;

	to_print = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\\' && ft_isalnum(cmd[i + 1]) == 0 && (i = i + 1))
			to_print = gnl_strjoin(to_print, ft_substr(cmd, i, 1), 2);
		else if (cmd[i] == '$' && ((ft_isalnum(cmd[i + 1]) == 1
			&& ft_isspace(cmd[i + 1]) == 0) || cmd[i + 1] == '_'))
			break ;
		else if (cmd[i] == quote)
			break ;
		else
			to_print = gnl_strjoin(to_print, ft_substr(cmd, i, 1), 2);
		i++;
	}
	write(1, to_print, ft_strlen(to_print));
	if (to_print)
		free(to_print);
	if (cmd[i] == '$')
		i = echo_dollar(dir_p->envp, cmd, i + 1, quote);
	if (cmd[i] != quote && cmd[i] != 0)
		return (echo_quotes(dir_p, cmd, i, quote));
	return (i);
}

int				handler_echo_special_char(t_dir *dir_p, char *cmd, int i)
{
	if (cmd[i] == '\\')
	{
		i++;
		write(1, &cmd[i], 1);
	}
	else if ((cmd[i] == '\"' || cmd[i] == '\'') && cmd[i - 1] != '\\')
		i = echo_quotes(dir_p, cmd, i + 1, cmd[i]);
	else if (cmd[i] == '$' && cmd[i + 1] == '?' && (i = i + 1))
		ft_putnbr_fd(dir_p->ret_last, 1);
	else if (cmd[i] == '$' && (ft_isalnum(cmd[i + 1]) == 1
		|| cmd[i + 1] == '_') && ft_isspace(cmd[i + 1]) == 0)
		i = echo_dollar(dir_p->envp, cmd, i + 1, '\0');
	else if (ft_isspace(cmd[i]) == 1)
	{
		while (cmd[i] && ft_isspace(cmd[i]) == 1)
			i++;
		if (cmd[i] != 0)
			write(1, " ", 1);
		i--;
	}
	else if (cmd[i] != '$' || (cmd[i] == '$'
			&& cmd[i + 1] != '\'' && cmd[i + 1] != '\"'))
		write(1, &cmd[i], 1);
	return (i);
}

void			handler_echo(t_dir *dir_p, char *cmd)
{
	int		no_new_line;
	int		i;

	no_new_line = 0;
	i = 0;
	while (cmd[i] && ft_isspace(cmd[i]) == 1)
		i++;
	while (cmd[i] && ft_isalnum(cmd[i]))
		i++;
	i = skip_flag(cmd, i, &no_new_line, 'n');
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			i = (cmd[i + 1] == '>') ? i + 1 : i;
			i = skip_filename(cmd, i);
		}
		else
			i = handler_echo_special_char(dir_p, cmd, i);
		if (cmd[i])
			i++;
	}
	if (no_new_line == 0)
		write(1, "\n", 1);
}
