/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:34:14 by elaignel          #+#    #+#             */
/*   Updated: 2021/01/22 15:17:56 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_prompt(int check)
{
	char	path[2048];
	int		i;

	i = 0;
	getcwd(path, sizeof(path));
	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	write(2, "\e[1m", ft_strlen("\e[1m"));
	write(2, "\e[92m", ft_strlen("\e[92m"));
	if (check == 0)
		write(2, "✔︎  ", ft_strlen("✔︎  "));
	write(2, "\e[91m", ft_strlen("\e[91m"));
	if (check == 1)
		write(2, "✘  ", ft_strlen("✘  "));
	write(2, "\e[96m", ft_strlen("\e[96m"));
	write(2, "\e[1m", ft_strlen("\e[1m"));
	write(2, path + i + 1, ft_strlen(path + i + 1));
	write(2, " ", 1);
	write(2, "\e[0m", ft_strlen("\e[0m"));
}

char	*call_command(char *old_cmd, char *new_cmd, int i, t_dir *dir_p)
{
	if (new_cmd && new_cmd[i] && errno == 0)
	{
		if (ft_strcmp(new_cmd + i, "pwd") == 0)
			handler_pwd(dir_p);
		else if (check_command(new_cmd + i, "cd", 2) == 0)
			handler_cd(dir_p, new_cmd + i);
		else if (check_command(new_cmd + i, "echo", 4) == 0)
			handler_echo(dir_p, old_cmd);
		else if (check_command(new_cmd + i, "env", 3) == 0)
			handler_env(dir_p);
		else if (check_command(new_cmd + i, "export", 6) == 0)
			handler_export(dir_p, old_cmd + i);
		else if (check_command(new_cmd + i, "unset", 5) == 0)
			handler_unset(dir_p, new_cmd + i);
		else if (check_command(new_cmd + i, "exit", 4) == 0)
			handler_exit(dir_p, new_cmd);
		else
			dir_p->ret_last = handler_execve(dir_p, new_cmd + i);
	}
	return (new_cmd);
}

int		choose_ft(char *old_cmd, t_dir *dir_p)
{
	int		i;
	char	*new_cmd;

	i = 0;
	if (handle_quotes(old_cmd) == -1)
		return (print_errors(-1));
	new_cmd = handle_redirect(old_cmd, dir_p);
	update_underscore_env(dir_p, new_cmd);
	if (old_cmd[0] == '<' || old_cmd[0] == '>')
		old_cmd = old_cmd + skip_filename(old_cmd, 0);
	if (check_pipes(old_cmd) > 0)
		handle_pipes(dir_p, new_cmd);
	else
	{
		while (new_cmd && new_cmd[i] && ft_isspace(new_cmd[i]) == 1)
			i++;
		new_cmd = call_command(old_cmd, new_cmd, i, dir_p);
	}
	ft_strdel(new_cmd);
	free(dir_p->tab_spaces);
	dir_p->tab_spaces = NULL;
	if (errno == 0)
		dir_p->ret_last = 0;
	errno = (errno == -258) ? 0 : errno;
	return (dir_p->ret_last);
}

void	parse_command(int i, char **sep_cmd, t_dir *dir_p)
{
	sep_cmd = ft_split(dir_p->gnl_line, ';');
	i = 0;
	while (sep_cmd[i])
	{
		dir_p->stdout = dup(STDOUT_FILENO);
		dir_p->stdin = dup(STDIN_FILENO);
		dir_p->pipe = 0;
		if (!(dir_p->tab_spaces = malloc(sizeof(int))))
			return ;
		dir_p->tab_spaces[0] = 0;
		dir_p->ret_last = choose_ft(sep_cmd[i], dir_p);
		if (errno != 0 && errno != -258)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			write(2, "\n", 1);
			dir_p->ret_last = 1;
			errno = 0;
		}
		i++;
		dup2(dir_p->stdout, STDOUT_FILENO);
		dup2(dir_p->stdin, STDIN_FILENO);
	}
	ft_strdel_xy(sep_cmd);
}

int		minishell(char **envp)
{
	int		ret;
	t_dir	dir_p;
	int		check;
	int		i;
	char	**sep_cmd;

	i = 0;
	check = 0;
	sep_cmd = 0;
	handler_signal();
	init_env(&dir_p, envp);
	dir_p.tab_spaces = NULL;
	dir_p.ret_last = 0;
	display_prompt(0);
	while ((ret = get_next_line(1, &dir_p.gnl_line)) > 0)
	{
		parse_command(i, sep_cmd, &dir_p);
		free(dir_p.gnl_line);
		if (ret == 0)
			break ;
		display_prompt(check);
	}
	free_struct(&dir_p);
	return (dir_p.ret_last);
}
