/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:34:49 by elaignel          #+#    #+#             */
/*   Updated: 2021/01/21 12:34:49 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_pwd(t_dir *dir_p)
{
	dir_p->pipe = 1;
	dir_p->path = getcwd(NULL, 0);
	write(1, dir_p->path, ft_strlen(dir_p->path));
	write(1, "\n", 1);
	free(dir_p->path);
}
