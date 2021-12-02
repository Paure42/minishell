/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:54:01 by paure             #+#    #+#             */
/*   Updated: 2021/01/21 09:54:03 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char		*free_strs(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (0);
}

int			gnl_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char		*readline(int fd, char *str)
{
	char	*buff;
	int		i;

	if (!str)
		if (!(str = (char*)ft_calloc(1, sizeof(char))))
			return (0);
	if (!(buff = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (free_strs(str, buff));
	while ((i = gnl_strchr(str, '\n')) == 0)
	{
		if ((i = read(fd, buff, BUFFER_SIZE)) < 0)
			return (free_strs(str, buff));
		buff[i] = 0;
		if (!(str = gnl_strjoin(str, buff, 0)))
			return (free_strs(str, buff));
		if (str[0] == 0 || i == 0 || i < BUFFER_SIZE)
			break ;
	}
	if (buff)
		free(buff);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[255];
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
		!(str[fd] = readline(fd, str[fd])))
		return (-1);
	if ((i = gnl_strchr(str[fd], '\n')) > 0)
	{
		if (i == 1)
			*line = ft_strdup("");
		else if (!(*line = gnl_substr(str[fd], 0, i - 1, 0)))
			return (-1);
		str[fd] = gnl_substr(str[fd], i, gnl_ft_strlen(str[fd]) - i, 1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}
