/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:55:28 by twagner           #+#    #+#             */
/*   Updated: 2022/01/11 17:35:28 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

/*
** SIMPLE COMMAND
** Execute a simple command (command with/ without parameters).
** The input of the simple command is an arg list with the command as last arg
*/

static int	ms_command_launcher(char **args)
{
	int		ret;
	char	**envp;

	if (ms_getbin_path(&args[0]) == ERROR)
		return (ERROR);
	envp = ms_g_envp_to_envp();
	if (!envp)
		return (ERROR);
	ret = execve(args[0], args, envp);
	ms_free_str_array(envp);
	if (ret == ERROR)
	{
		if (errno == EAGAIN)
			ret = 126;
		else
			ret = 127;
	}
	return (ret);
}

/*
** EXECUTE
** This function executes a bin command. It will fork before so the 
** command is executed in a specific process and it will handle signal
** for interruption of child process.
*/

static int	ms_execute(char **args)
{
	pid_t				pid;
	pid_t				wpid;
	int					status;

	pid = fork();
	if (pid == ERROR)
		return (ERROR);
	if (pid == 0)
	{
		ms_activate_signal_handler();
		exit(ms_command_launcher(args));
	}
	else
	{
		ms_ignore_signals();
		wpid = waitpid(pid, &status, 0);
		if (wpid == ERROR)
			return (ERROR);
	}
	return (ms_get_exit_status(status));
}

/*
** VISIT AST FOR SIMPLE COMMAND
** This function will visit a tree from the root and build an array
** with every arguments and the command in the tree.
** The commands are searched only in a pipe command scope.
*/

static char	**ms_visit(t_node *node, char **args, int exit_code)
{
	if (!args || !node || (node && node->type == A_PIPE))
		return (args);
	args = ms_visit(node->left, args, exit_code);
	args = ms_visit(node->right, args, exit_code);
	if (node->type == A_PARAM)
	{
		if (ft_strcmp(node->data, "$?") == 0)
			args = ms_add_arg_back(args, ft_itoa(exit_code));
		else
			args = ms_add_arg_back(args, node->data);
	}
	else if (node->type == A_CMD)
	{
		if (ft_strcmp(node->data, "$?") == 0)
			args = ms_add_arg_back(args, ft_itoa(exit_code));
		else
			args = ms_add_arg_back(args, node->data);
	}
	return (args);
}

/*
** EXEC SIMPLE COMMAND
** This function will create an array from the AST for one simple command,
** then it will check if the command is a builtin or not, and pass the array
** to execve or execute_builtin.
** it will then restore STDIN and STDOUT in case of a simple redir command.
*/

int	ms_exec_simple_command(t_node *ast, int exit_code, int *fd)
{
	char	**args;
	int		ret;

	ret = 0;
	args = ms_visit(ast, ms_init_arg_array(), exit_code);
	if (args)
	{
		if (args[0])
		{
			if (ms_is_builtin(args[0]))
				ret = ms_execute_builtin(args);
			else
				ret = ms_execute(args);
			if (!ms_is_builtin(args[0]) && ret > 0 && ret < 128)
				ms_print_exec_error(args[0], ret);
		}
		ms_free_str_array(args);
	}
	else
		ret = ERROR;
	if (fd[0] != -1)
		if (ms_restore_std_fd(fd) == ERROR)
			ret = ERROR;
	return (ret);
}

/*
** EXEC PIPED COMMAND
** This function is the same as exec simple command but it will not
** fork as the fork appens before in the pipeline management and it will
** not restore fds as every sub process ends and will return to minishell.
*/

int	ms_exec_piped_command(t_node *ast, int exit_code)
{
	char	**args;
	int		ret;

	ret = 0;
	args = ms_visit(ast, ms_init_arg_array(), exit_code);
	if (args)
	{
		if (args[0])
		{
			if (ms_is_builtin(args[0]))
				ret = ms_execute_builtin(args);
			else
				ret = ms_command_launcher(args);
			if (ret > 0 && ret < 128)
				ms_print_exec_error(args[0], ret);
		}
		ms_free_str_array(args);
	}
	else
		ret = 1;
	return (ret);
}
