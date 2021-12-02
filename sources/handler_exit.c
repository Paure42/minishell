/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:57:07 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 10:57:07 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_exit(t_dir *dir_p, char *new_cmd)
{
	int		i;
	char	**cmd_spl;

	cmd_spl = ft_split(new_cmd, ' ');
	i = ft_strlen_2d(cmd_spl);
	if (i == 1)
	{
		free_struct(dir_p);
		exit(0);
	}
	else if (i == 2)
	{
		i = atoi(cmd_spl[1]);
		free_struct(dir_p);
		exit(i);
	}
	else
	{
		ft_putstr_fd("Error : multiple argument are invalid for exit\n", 2);
		dir_p->ret_last = 1;
	}
}
