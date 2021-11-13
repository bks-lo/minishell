/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:31:08 by twagner           #+#    #+#             */
/*   Updated: 2021/11/13 15:44:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

char	ms_ctrl_key(char key)
{
	return (key & 0x1f);
}

int	ms_disable_raw_mode(struct termios *orig_termios)
{
	return (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios));
}

int	ms_enable_raw_mode(struct termios *orig_termios)
{
	// voir BRKINT, ISIG pour autoriser les Ctrl C
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, orig_termios) == ERROR)
		return (ERROR);
	raw = *orig_termios;
	raw.c_iflag &= ~(BRKINT | INPCK | ISTRIP | IXON);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN); // + ISIG
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}
