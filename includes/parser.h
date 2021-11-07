/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:18:13 by twagner           #+#    #+#             */
/*   Updated: 2021/11/06 15:07:36 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"
# include "token.h"
# include "ast.h"

/*
** PARSER DEFINES
*/
# define NB_TRANS 172
# define ACTION 114
# define GOTO 58
# define AUTOMATON "./srcs/parser/parser/automaton"
# define NO_ACTION -1
# define DEFAULT -1
# define SHIFT 0
# define REDUCE 1
# define ACCEPT 2

typedef enum e_rules
{
	R_AND_OR = 100,
	R_PIPE_SEQUENCE,
	R_SIMPLE_COMMAND,
	R_CMD_NAME,
	R_CMD_WORD,
	R_CMD_PREFIX,
	R_CMD_SUFFIX,
	R_IO_REDIRECT,
	R_IO_FILE,
	R_FILENAME,
	R_IO_HERE,
	R_HERE_END
}	t_rules;

/*
** PARSER STRUCTURES
*/

typedef struct s_trans
{
	int	state;
	int	event;
	int	action;
	int	next;
	int	nb_reduce;
}		t_trans;

typedef struct s_stack
{
	int				type;
	int				state;
	void			*data;
	struct s_stack	*next;
}	t_stack;

/*
** PARSER FUNCTIONS
*/
int		ms_ast_builder(t_ast_builder **builder, t_stack **popped, int reduction);
t_trans	**ms_init_parsing_table(void);
void	ms_free_table(t_trans **trans);
t_stack	*ms_new_stack_item(void *content, int type, int state);
t_stack	**ms_pop_stack(t_stack **stack, int nb);
int		ms_add_front(t_stack **stack, t_stack *item);
void	ms_free_stack_item(t_stack *stack);
int		ms_free_stack(t_stack **stack, int return_code);
t_node	*ms_parser(t_token *tok_list, t_trans **table);

#endif