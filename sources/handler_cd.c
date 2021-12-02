/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaignel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:33:40 by elaignel          #+#    #+#             */
/*   Updated: 2021/01/21 12:33:41 by elaignel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	new_pwd_env(t_dir *dir_p, char *cmd, int x)
{
	char	*oldpath;
	char	*tmp;
	char	*tmp2;

	oldpath = NULL;
	tmp = NULL;
	tmp2 = NULL;
	if (x == 0)
	{
		if ((tmp = ft_getenv(dir_p->envp, "PWD")) == NULL)
			tmp = getcwd(NULL, 0);
		oldpath = ft_strjoin(cmd, tmp);
	}
	else if (x == 1)
	{
		tmp2 = getcwd(NULL, 0);
		oldpath = ft_strjoin("export PWD=", tmp2);
		ft_strdel(tmp2);
	}
	handler_export(dir_p, oldpath);
	ft_strdel(oldpath);
	if (tmp)
		free(tmp);
}

char	*replace_tilde(t_dir *dir_p, char *cd)
{
	char	*home;
	char	*newpath;
	char	*ap_tilde;

	home = ft_getenv(dir_p->envp, "HOME");
	if (ft_strlen(cd) <= 1)
		return (home);
	ap_tilde = ft_strdup(ft_strchr(cd, '~') + 1);
	newpath = ft_substr(cd, 0, ft_strlen(cd) - (ft_strlen(ap_tilde) + 1));
	newpath = gnl_strjoin(newpath, home, 0);
	newpath = gnl_strjoin(newpath, ap_tilde, 1);
	return (newpath);
}

char	**init_cd(char *cd, t_dir *dir_p, int *len)
{
	char	**spl;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(cd);
	tmp2 = var_string(tmp, dir_p);
	spl = ft_split(tmp2, ' ');
	*len = ft_strlen_2d(spl);
	new_pwd_env(dir_p, "export OLDPWD=", 0);
	if (tmp != tmp2)
		ft_strdel(tmp);
	ft_strdel(tmp2);
	return (spl);
}

int		handle_tilde(t_dir *dir_p, char *path, char **spl)
{
	path = replace_tilde(dir_p, " ");
	chdir(path);
	ft_strdel(path);
	ft_strdel_xy(spl);
	return (1);
}

void	handler_cd(t_dir *dir_p, char *cd)
{
	int		len;
	char	*path;
	char	**spl;
	int		f;

	spl = init_cd(cd, dir_p, &len);
	path = NULL;
	f = 0;
	if (len == 1 && handle_tilde(dir_p, path, spl))
		return ;
	if (len == 2)
		if (ft_strchr(spl[1], '~') != 0)
			path = replace_tilde(dir_p, spl[1]);
	if (path == NULL)
		path = spl[1];
	else
		f = 1;
	if (len == 2 && chdir(path) == -1)
		dir_p->ret_last = 1;
	if (f == 1)
		ft_strdel(path);
	ft_strdel_xy(spl);
	new_pwd_env(dir_p, "export PWD=", 1);
}
