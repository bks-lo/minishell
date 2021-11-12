/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:55:28 by twagner           #+#    #+#             */
/*   Updated: 2021/11/12 14:54:10 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "parser.h"

/*
** INTERPRETER
** The interpreter browse the AST in a certain order and push the arguments
** to the right executer (pipeline, command, simple command)
*/

static int	ms_search_ast(t_node *node, int needle, int nb)
{
	if (!node)
		return (nb);
	if (node->type == needle)
		++nb;
	nb = ms_search_ast(node->left, needle, nb);
	nb = ms_search_ast(node->right, needle, nb);
	return (nb);
}

int	ms_execute_ast(t_node *ast, char **envp)
{
	int			nb_pipe;
	int			nb_redir_end;

	nb_pipe = ms_search_ast(ast, A_PIPE, 0);
	nb_redir_end = ms_search_ast(ast, A_RED_TO, 0) \
		+ ms_search_ast(ast, A_RED_FROM, 0) + ms_search_ast(ast, A_DGREAT, 0) \
		+ ms_search_ast(ast, A_DLESS, 0);
	if (nb_pipe && ms_exec_pipeline(ast, envp, nb_pipe) == ERROR)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
	if (nb_redir_end && ms_exec_command(ast, envp) == ERROR)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
	if (ms_exec_simple_command(ast, envp) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}