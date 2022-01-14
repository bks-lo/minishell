/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:33:35 by twagner           #+#    #+#             */
/*   Updated: 2022/01/14 22:49:54 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H
# include "parser.h"

# define BUFFER_SIZE 32

/*
** STRUCTURES
*/
typedef struct s_pipe
{
	int				fd[2];
	int				is_curr_read;
	int				is_curr_write;
	struct s_pipe	*next;
}					t_pipe;

typedef enum e_pipe_ends
{
	READ_END,
	WRITE_END
}	t_pipe_ends;

/*
** FUNCTIONS
*/

int		ms_getbin_path(char **bin);
char	**ms_init_arg_array(void);
char	**ms_add_arg_back(char **array, char *data);
void	ms_free_arg_array(char **array);

int		ms_is_builtin(char *command);
int		ms_execute_builtin(char **args);

int		ms_exec_pipeline(t_node *ast, int nb, int *hd_fds);
int		ms_exec_simple_command(t_node *ast, int *fd);
int		ms_exec_piped_command(t_node *ast);

int		ms_do_redirections(t_node *node, int ret, int *hd_fds);
void	ms_save_std_fd(int *fd);
int		ms_restore_std_fd(int *fd);

t_pipe	*ms_init_pipes(int nb);
void	ms_free_pipe_list(t_pipe *pipe);
void	ms_update_curr_fds(t_pipe *pipe);
void	ms_connect_pipe(t_pipe *pipe);
void	ms_close_unused_fds(t_pipe *pipe);

int		ms_search_ast(t_node *node, int needle, int nb);

void	ms_activate_signal_handler(void);
void	ms_ignore_signals(void);
int		ms_get_exit_status(int status);

void	ms_print_exec_error(char *cmd, int error_code);

int		*ms_do_heredoc(t_node *tree, int nb, int *interrupt);
char	*ms_init_keep_buffer(void);
char	*ms_search_limiter(char *buffer, char *limiter);
int		ms_clear_heredoc(int *heredoc_fds, int ret);
char	*ms_get_next_heredoc(char *limiter, int tofree);
void	ms_restore_default_signals(void);
void	ms_activate_hd_signal_handler(void);
int		ms_reopen_heredoc_fds(\
	int fd, char *file_name, int *heredoc_fds, int num);
int		ms_gnh_keep_buffer_management(int tofree, char **keep_buffer);
char	*ms_join_and_check_bufs(\
	char **keep_buffer, char *buffer, char *limiter);
void	ms_reinit_keep_buffer(char **keep_buffer);
int		ms_write_hd(int fd, char *file_content, int len);
int		ms_dollar_expansion(char **str);

#endif
