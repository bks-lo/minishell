/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:14:53 by twagner           #+#    #+#             */
/*   Updated: 2021/11/12 16:09:55 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

t_env	*g_my_envp;

/*
** GLOBAL PARAMS
*/
# define ERROR -1
# define ERROR_BIN_NOT_FOUND 127

/*
** CORE FUNCTIONS
*/
int		ms_execute(char **args, char **envp);
int		ms_is_builtin(char *command);
int		ms_execute_builtin(char **args, char **envp);

/*
** BUILTINS
*/

int		ms_echo(int ac, char **av);
int		ms_cd(int ac, char **av);
int		ms_pwd(int ac, char **av);
int		ms_env(int ac, char **av, char **envp);
int		ms_export(int ac, char **av, char **envp);
void	printf_out_env(t_env *list);
t_env	*init_env(char **envp);
int		ms_unset(int ac, char **av, char **envp);
int		ms_exit(int ac, char **av);

#endif