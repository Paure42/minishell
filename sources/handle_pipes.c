/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:04:21 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:04:22 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_args(char *cmd)
{
	char	**args;
	int		nb;

	nb = 0;
	args = ft_split(cmd, '|');
	while (args[nb])
		nb++;
	ft_strdel_xy(args);
	return (nb);
}

int		check_pipes(char *cmd)
{
	int		i;
	int		check_pipe;

	i = 0;
	check_pipe = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			i = skip_quotes_int(cmd, '\'', i + 1);
		else if (cmd[i] == '\"')
			i = skip_quotes_int(cmd, '\"', i + 1);
		else if (cmd[i] == '|')
		{
			check_pipe++;
		}
		if (cmd[i])
			i++;
	}
	if (check_args(cmd) <= 1)
		check_pipe = 0;
	return (check_pipe);
}

void	dup_io(t_dir *dir_p)
{
	dup2(dir_p->stdout, STDOUT_FILENO);
	dup2(dir_p->stdin, STDIN_FILENO);
}

void	swap_fd(t_dir *dir_p, char **cmd_spl, int fd_temp, int *fd)
{
	dup2(fd_temp, STDIN_FILENO);
	if (cmd_spl[dir_p->i + 1] != NULL)
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	child_execve(dir_p, cmd_spl[dir_p->i]);
}

void	handle_pipes(t_dir *dir_p, char *cmd)
{
	int		fd[2];
	pid_t	pid;
	int		fd_temp;
	char	**cmd_spl;

	dir_p->i = 0;
	fd_temp = 0;
	dup_io(dir_p);
	cmd_spl = ft_split(cmd, '|');
	while (cmd_spl[dir_p->i])
	{
		if (pipe(fd) < 0 || (pid = fork()) < 0)
			return ;
		else if (pid == 0)
			swap_fd(dir_p, cmd_spl, fd_temp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			close(fd[1]);
			fd_temp = fd[0];
			dir_p->i++;
		}
	}
	ft_strdel_xy(cmd_spl);
}
