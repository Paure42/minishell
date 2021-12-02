/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:07:55 by paure             #+#    #+#             */
/*   Updated: 2021/01/22 15:18:13 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler_ctrl_c(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	display_prompt(1);
	sig = 0;
}

void	handler_ctrl_bslash(int sig)
{
	(void)sig;
	sig = 0;
}

void	handler_signal(void)
{
	signal(SIGINT, handler_ctrl_c);
	signal(SIGQUIT, handler_ctrl_bslash);
}
