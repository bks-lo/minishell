/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:14:41 by twagner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/16 10:35:10 by ifeelbored       ###   ########.fr       */
=======
/*   Updated: 2022/01/15 17:14:04 by twagner          ###   ########.fr       */
>>>>>>> d0be14e1ff52f84ee256005de7610575217eecd8
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

t_env	*g_envp = NULL;

/*
** SPECIAL STATUS
** Display Quit if exit status == 131 and add new line if exit status > 128
*/

static void	ms_display_special_status(int status)
{
	if (status == 131)
		printf("Quit : %i\n", status - 128);
	else if (status > 128)
		printf("\n");
}

/*
** INIT LOOP
** Init the parsing table and the main variables of minishell loop
*/

static int	ms_init_loop(\
	t_history **histo, t_trans ***parsing_table, int *status)
{
	*histo = NULL;
	*status = 0;
	*parsing_table = ms_init_parsing_table();
	if (!*parsing_table)
		return (ERROR);
	return (0);
}

/*
** MINISHELL ROUTINE
** parse / execute
*/

static void	ms_routine(\
	char *line, int *status, t_trans **parsing_table, t_history *histo)
{
	t_node			*ast;
	t_garbage_coll	*garcol;

	ast = ms_parser(ms_tokenizer(line, *status), parsing_table);
	if (!ast)
		write(2, "minishell: syntax error\n", 24);
	garcol = ms_init_garbage_coll(histo, parsing_table, ast);
	if (!garcol)
		*status = ERROR;
	else
		*status = ms_execute_ast(ast, garcol);
	free(garcol);
	ms_clear_tree(&ast);
	ms_display_special_status(*status);
}

/*
** LOOP
** display a prompt, get a command, execute it, loop
*/

static int	ms_loop(struct termios *termios)
{
	char		*line;
	int			status;
	t_history	*histo;
	t_trans		**parsing_table;

	if (ms_init_loop(&histo, &parsing_table, &status) == ERROR)
		status = ERROR;
	while (status >= 0)
	{
		if (ms_enable_raw_mode(termios) == ERROR)
		{
			status = ERROR;
			break ;
		}
		line = ms_readline(&histo);
		ms_disable_raw_mode(termios);
		if (line)
<<<<<<< HEAD
		{
			ast = ms_parser(ms_tokenizer(line, status), parsing_table);
			if (!ast)
				printf("minishell: syntax error\n");
			status = ms_execute_ast(ast);
			//ms_clear_tree(&ast);
			ms_display_special_status(status);
		}
=======
			ms_routine(line, &status, parsing_table, histo);
>>>>>>> d0be14e1ff52f84ee256005de7610575217eecd8
		else
			printf("\n");
	}
	ms_histo_clear(histo);
	ms_free_table(parsing_table);
	return (status);
}

/*
** MAIN
** Minishell launcher, handle the env variables then launch the loop
*/

int	main(int ac, char **av, char **envp)
{
	struct termios	orig_termios;
	char			*term_type;
	int				exit_code;

	(void)ac;
	(void)av;
	g_envp = init_env(envp);
	if (g_envp == NULL || ms_increment_shlvl() == ERROR)
	{
		ms_clearenv();
		return (EXIT_FAILURE);
	}
	term_type = ms_getenv("TERM");
	if (tgetent(NULL, term_type) != 1)
	{
		ms_clearenv();
		return (EXIT_FAILURE);
	}
	exit_code = ms_loop(&orig_termios);
	ms_disable_raw_mode(&orig_termios);
	ms_clearenv();
	if (exit_code == ERROR)
		return (EXIT_FAILURE);
	return ((exit_code * -1) - 2);
}
