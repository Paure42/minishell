/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:20 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:23:21 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	loop_execve(t_dir *dir_p, char **path_spl, char **cmd_spl)
{
	dir_p->p_tmp = gnl_strjoin(
		ft_strjoin(path_spl[dir_p->x], "/"), cmd_spl[0], 0);
	while (path_spl[dir_p->x] != NULL && execve(dir_p->p_tmp,
		cmd_spl, dir_p->envp) == -1)
	{
		ft_strdel(dir_p->p_tmp);
		dir_p->p_tmp = gnl_strjoin(
			ft_strjoin(path_spl[dir_p->x], "/"), cmd_spl[0], 0);
		dir_p->x++;
	}
	if (errno != 0)
	{
		ft_putstr_fd("Invalid command\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_strdel_xy(cmd_spl);
	ft_strdel_xy(path_spl);
}

void	try_execve(t_dir *dir_p, char **path_spl, char **cmd_spl)
{
	if (execve(cmd_spl[0], cmd_spl, dir_p->envp) == -1)
	{
		dir_p->vepath = ft_getenv(dir_p->envp, "PATH");
		path_spl = ft_split(dir_p->vepath, ':');
		if (path_spl[0] == NULL)
		{
			ft_putstr_fd("Invalid $PATH\n", 2);
			exit(EXIT_FAILURE);
		}
		loop_execve(dir_p, path_spl, cmd_spl);
	}
}

void	child_execve(t_dir *dir_p, char *cmd)
{
	char	**path_spl;
	char	**cmd_spl;

	dir_p->x = 0;
	path_spl = 0;
	dir_p->vepath = 0;
	cmd = var_string(cmd, dir_p);
	cmd_spl = ft_split(cmd, ' ');
	dir_p->tmp = 0;
	try_execve(dir_p, path_spl, cmd_spl);
	ft_strdel(dir_p->vepath);
	ft_strdel(dir_p->tmp);
	dir_p->ret_last = 0;
	exit(0);
}

int		handler_execve(t_dir *dir_p, char *cmd)
{
	pid_t	c_pid;
	int		status;

	status = 0;
	if (dir_p->pipe == 0)
	{
		if ((c_pid = fork()) == 0)
			child_execve(dir_p, cmd);
		else
			waitpid(c_pid, &status, 0);
		if (status != 0)
		{
			dir_p->ret_last = 1;
			errno = -258;
		}
	}
	return (dir_p->ret_last);
}
