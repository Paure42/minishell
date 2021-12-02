/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:22:43 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:22:44 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_command(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < (n - 1)
			&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (s1[i] != 0 && ft_isalnum(s1[i + 1]) == 1)
		return (-1);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*skip_quotes(char *cmd, char c)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == c)
		{
			if (i == 0)
				break ;
			else if (cmd[i - 1] != '\\')
				break ;
		}
		i++;
	}
	if (i)
		return (ft_substr(cmd, 0, i));
	else
		return (ft_calloc(1, 1));
}

char	*var_string2(char *cmd, t_dir *dir_p, int var, int *i)
{
	char	*temp;
	int		x;
	char	*new_var;

	temp = ft_substr(cmd, *i, var);
	if ((new_var = ft_getenv(dir_p->envp, temp + 1)) == 0)
		new_var = ft_substr(cmd, *i, var);
	x = ft_strlen(temp);
	var = ft_strlen(new_var) + ft_strlen(cmd) - x;
	ft_strdel(temp);
	if (!(temp = malloc(sizeof(char) * var)))
		return (NULL);
	*i = 0;
	while (cmd[*i])
	{
		if (cmd[*i] == '$')
			break ;
		temp[*i] = cmd[*i];
		*i = *i + 1;
	}
	temp[*i] = '\0';
	new_var = gnl_strjoin(new_var, cmd + *i + x, 0);
	temp = gnl_strjoin(temp, new_var, 2);
	return (temp);
}

char	*var_string(char *cmd, t_dir *dir_p)
{
	int		i;
	int		var;

	i = 0;
	var = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
		{
			var++;
			while (cmd[i + var] && (ft_isalpha(cmd[i + var]) == 1
				|| cmd[i + var] == '_'))
				var++;
			if (var > 1)
				return (var_string2(cmd, dir_p, var, &i));
		}
		i++;
	}
	return (cmd);
}

int		print_errors(int error)
{
	if (error == -1)
		ft_putstr_fd("Error missing matching quote\n", 2);
	return (-1);
}
