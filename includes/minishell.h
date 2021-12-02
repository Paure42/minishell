/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paure <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:22:59 by paure             #+#    #+#             */
/*   Updated: 2021/01/25 13:23:01 by paure            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <stdint.h>
# include <inttypes.h>
# include "../includes/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_dir_path
{
	char	**envp;
	char	*path;
	char	*gnl_line;
	int		fd_env;
	int		pipe;
	int		ret_last;
	int		stdout;
	int		stdin;
	int		*tab_spaces;
	int		i;
	int		x;
	char	*tmp;
	char	*p_tmp;
	char	*vepath;
}				t_dir;

int				main(int argc, char *argv[], char **envp);
int				minishell(char **envp);
int				check_command(char *s1, char *s2, size_t n);
void			display_prompt(int check);
int				handler_execve(t_dir *dir_p, char *cmp);
void			handler_pwd(t_dir *dir_p);
void			handler_cd(t_dir *dir_p, char *cd);
void			handler_echo(t_dir *dir_p, char *cmd);
void			handler_signal();
void			handler_env(t_dir *dir_p);
void			handler_unset(t_dir *dir_p, char *cmd);
void			handler_export(t_dir *dir_p, char *old_cmd);
int				handle_quotes(char *str);
char			*handle_redirect(char *cmd, t_dir *dir_p);
void			add_env(char *variable, t_dir *dir_p);
void			edit_var_env(int pos, t_dir *dir_p, char *variable);
void			add_var_env(t_dir *dir_p, char *variable);
void			del_var_env(t_dir *dir_p, int pos);
char			*del_quotes(char *str);
char			*skip_quotes(char *cmd, char c);
void			child_execve(t_dir *dir_p, char *cmd);
int				print_errors(int error);
int				skip_filename(char *cmd, int j);
char			*find_filename(char *cmd);
void			handle_pipes(t_dir *dir_p, char *cmd);
int				check_pipes(char *cmd);
void			free_struct(t_dir *dir_p);
int				*fill_tab_spaces(int *tab_spaces, int i);
void			free_tab_spaces(int *tab_spaces);
char			*var_string(char *cmd, t_dir *dir_p);
int				skip_quotes_int(char *cmd, char c, int i);
char			*erase_quotes(char *cmd, t_dir *dir_p);
int				skip_flag(char *cmd, int i, int *nl, char flag);
int				new_strchr(char *str, char c, int i);
char			*format_command(char *cmd, t_dir *p);
void			handler_exit(t_dir *dir_p, char *new_cmd);
char			*find_command(char *cmd);
void			update_underscore_env(t_dir *dir_p, char *cmd);
void			init_env(t_dir *dir_p, char **envp);
char			*var_string(char *cmd, t_dir *dir_p);

#endif
