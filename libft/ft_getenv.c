/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:57:10 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 09:57:11 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(char **spl)
{
	int i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

char	*ft_getenv(char **envp, char *name)
{
	char	**spl;
	char	*temp;
	int		i;

	i = 0;
	spl = NULL;
	temp = NULL;
	while (envp[i])
	{
		spl = ft_split(envp[i], '=');
		if (ft_strcmp(spl[0], name) == 0)
		{
			temp = ft_strdup(spl[1]);
			free_tab(spl);
			return (temp);
		}
		free_tab(spl);
		spl = NULL;
		i++;
	}
	if (spl != NULL)
		free_tab(spl);
	return (0);
}
