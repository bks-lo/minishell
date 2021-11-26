/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:33:35 by twagner           #+#    #+#             */
/*   Updated: 2021/11/26 11:34:08 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H
# include "parser.h"

/*
** FUNCTIONS
*/

int		ms_getbin_path(char **bin);
char	**ms_init_arg_array(void);
char	**ms_add_arg_back(char **array, char *data);
char	**ms_add_arg_front(char **array, char *cmd);
void	ms_free_arg_array(char **array);

int		ms_is_builtin(char *command);
int		ms_execute_builtin(char **args, char **envp);

int		ms_exec_pipeline(t_node *ast, char **envp, int nb_pipe);
int		ms_exec_command(t_node *ast, char **envp);
int		ms_exec_simple_command(t_node *ast, char **envp, int exit_code);
int		ms_exec_comb_command(t_node *node, char **envp, int nb_pipe);

#endif
