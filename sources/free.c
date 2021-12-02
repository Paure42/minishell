/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:03:45 by user42            #+#    #+#             */
/*   Updated: 2020/12/22 16:48:27 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_struct(t_dir *dir_p)
{
	if (dir_p)
	{
		ft_strdel(dir_p->gnl_line);
		ft_strdel_xy(dir_p->envp);
		if (dir_p->tab_spaces != NULL)
			free(dir_p->tab_spaces);
	}
}
