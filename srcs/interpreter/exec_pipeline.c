/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:55:34 by twagner           #+#    #+#             */
/*   Updated: 2021/11/16 15:05:42 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "parser.h"

static int	ms_cmd_len_2(char ***args)
{
	int	i;

	i = 0;
	printf("11111\n");
	if (!args)
		return (0);
	printf("2222222x\n");
	while (args[i])
		++i;
	return (i);
}

static int	ms_args_len_2(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		++i;
	return (i);
}

char	***ms_init_arg_array_2(int nb_pipe)
{
	char	***array;
	char	**arr;
	
	array = (char ***)malloc(sizeof(**array));
	if (!array)
		return (NULL);
	arr = (char **)malloc(sizeof(*arr) * (nb_pipe + 2));
	if (!arr)
		return (NULL);
	*array = arr;
	arr[nb_pipe + 1] =  NULL;
	(*arr) = NULL;
	return (array);
}

void	free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_path(paths);
			return (path);
		}
		free(path);
		i++;
	}
	if (paths)
		free_path(paths);
	return (0);
}

void print_arg(char ***argv, int nb_cmd)
{
	int i = 0;
	int nb = 0;

	while (nb < nb_cmd)
	{
		while(argv[nb][i])
		{
			printf("%s\n", argv[nb][i]);
			i++;
		}
		printf("\\\\\\n");
		nb++;
	}
}

// void pipe_execte(int *pipex, t_cmds *args, int nb_pipe, char **envp)
// {
// 	int		i;
// 	char	*path;
// 	//if not last cmds
// 	printf("inside:%d\n", args->i);
//     if (args->i !=nb_pipe)
// 	{
//         if (dup2(pipex[2 * args->i + 1], STDOUT_FILENO) < 0)
// 		{
// 			perror("dup a");
// 			exit(1);
// 		}
//     }
// 	//if not first cmd
// 	if (args->i != 0)
// 	{
//         if (dup2(pipex[2 * (args->i-1)], STDIN_FILENO) < 0)
// 		{
// 			perror("dup b");
// 			exit(1);
// 		}
//     }
// 	i = -1;
//     while(++i < nb_pipe * 2)	
// 		close(pipex[i]);
// 	printf("getpath:%s\n", args->cmds[0]);
// 	path = get_path(args->cmds[0], envp);
//     if (!path)
// 	{
// 		perror("path");
// 		exit(1);
// 	}
// 	if (execve(path, args->cmds, envp) == -1)
// 	{
// 		perror("execve");
// 		exit(1);
// 	}

// }
char	***ms_add_arg_back_2(char ***args, int nd_cmd, char *data)
{
	int		i;
	int		ac;
	char	**new;

	if (!args)
		return (NULL);
	ac = ms_args_len_2(args[nd_cmd]);
	new = (char **)malloc(sizeof(*new) * (ac + 2));
	if (!new)
	{
		//ms_free_arg_array(args);
		return (NULL);
	}
	new[ac + 1] = NULL;
	i = -1;
	while (args[nd_cmd][++i])
		new[i] = ft_strdup(args[nd_cmd][i]);
	new[i] = ft_strdup(data);
	//ms_free_arg_array(args);
	return (args);
}

char	***ms_add_arg_front_2(char ***args, int nd_cmd , char *cmd)
{
	int		i;
	int		ac;
	char	**new;

	if (!args)
		return (NULL);
	ac = ms_args_len_2(args[nd_cmd]);
	new = (char **)malloc(sizeof(*new) * (ac + 2));
	if (!new)
	{
		//ms_free_arg_array_2(args);
		return (NULL);
	}
	new[ac + 1] = NULL;
	new[0] = ft_strdup(cmd);
	i = -1;
	while (args[nd_cmd][++i])
		new[i + 1] = ft_strdup(args[nd_cmd][i]);
	//ms_free_arg_array(args);
	return (args);
}

static char ***ms_visit(t_node *node, char ***args, char **envp, int *pipex, int nb_pipe)
{
	pid_t		child;
	int			i;
	int			nd_pipx;
	int			nd_cmd;

	if (!node)
		return (args);
	nd_pipx = 0;
	nd_cmd = ms_cmd_len_2(args);
	printf("here???\n");
	args = ms_visit(node->left, args, envp, pipex, nb_pipe);
	args = ms_visit(node->right, args, envp, pipex ,nb_pipe);
	if (node->type == A_PIPE)
	{
		nd_pipx++;
		if (nd_pipx == nb_pipe)
		{
			printf("HELLOOOOO\n");
			print_arg(args, nd_cmd);
		}
		// if last pipe > launch pipex
		// if not > Connect cmd 1 output to cmd 2 input
	}
	if (node->type == A_PARAM)
	{
		nd_cmd = ms_cmd_len_2(args);
		args = ms_add_arg_back_2(args, nd_cmd, node->data);
		nd_cmd = ms_cmd_len_2(args);
		printf("back:%s, %s, %d \n", node->data, args[nd_cmd][0], ms_cmd_len_2(args));
	}
	else if (node->type == A_CMD)
	{	
		nd_cmd = ms_cmd_len_2(args);
		args = ms_add_arg_front_2(args, nd_cmd, node->data);
		nd_cmd = ms_cmd_len_2(args);
		printf("front:%s, %s, %d \n", node->data, args[nd_cmd][0], ms_cmd_len_2(args));
		// Save the args tab in an array
		// if (args->cmds)
		// 	printf("cmds:%s\n", args->cmds[0]);
		if (!args)
			return (NULL);
		child = fork();
		if (child < 0)
		{
			perror("fork");
			exit(1);
		}
		if (child == 0)
		{
			printf("childe\n");
			printf("----\n");
			printf("----\n");
			//pipe_execte(pipex, args, nb_pipe, envp);
		}
		//parent
		//args = ms_init_arg_array_2();
		//args->i = (args->i) + 1;
		i = -1;
		while(++i < nb_pipe * 2)
			close(pipex[i]);
		while (errno != ECHILD)
			wait(NULL);
	}
	return (args);
}

int		*pipex_creat(int nb_pipe)
{
	int		*pipex;
	int		i;

	pipex = malloc(nb_pipe * 2 * sizeof(int));
	if (!pipex)
	{
		perror("pipe");
		exit(1);
	}
	i = -1;
	while(++i < nb_pipe)
	{
		if (pipe(&pipex[2 * i]) < 0)
		{
			perror("pipe");
			exit(1);
		}
	}
	return pipex;
}

int	ms_exec_pipeline(t_node *node, char **envp, int nb_pipe)
{
	char	***args;
	int		*pipex;

	(void)node;
	(void)envp;
	pipex = pipex_creat(nb_pipe);
	printf("first\n");
	args = ms_init_arg_array_2(nb_pipe);
	printf("secodne\n");
	args = ms_visit(node, args, envp, pipex, nb_pipe);
	// if (!args)
	// {
	// 	ms_free_arg_array(args);
	// 	return (ERROR);
	// }
	// ms_free_arg_array(args);
	return (EXIT_SUCCESS);
}
