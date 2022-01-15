/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:44:33 by twagner           #+#    #+#             */
/*   Updated: 2022/01/15 10:31:18 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_pwd(int ac, char **av)
{
	char	*path;
	
	(void)av;
	if (ac > 1)
	{
		printf("usage: pwd\n");
		return (2);
	}
	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
	return (0);
}
