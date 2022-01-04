/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:57:26 by twagner           #+#    #+#             */
/*   Updated: 2022/01/04 11:45:08 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_len(char *c)
{
	int	len;

	len = 0;
	while (c[len])
	{
		if (ft_isalnum(c[len]) || c[len] == '_')
			len++;
		else
			return (len);
	}
	return (len);
}

int	ft_strchr_index(char *s, char c)
{
	int	len;

	len = -1;
	while (s[++len])
	{
		if (s[len] == c)
			return (len);
	}
	return (0);
}

char	*replcace_var_2(char *cmd, char *var, char *newvar, int index)
{
	char	*newcmd;
	int		len;
	int		i;
	int		y;

	len = ft_strlen(cmd) - ft_strlen(var) - 1 + ft_strlen(newvar);
	newcmd = malloc((len + 1) * sizeof(char));
	if (!newcmd)
		return (0);
	i = 0;
	y = 0;
	while (y < index)
		newcmd[i++] = (cmd)[y++];
	while (newvar && *newvar)
	{
		newcmd[i] = *newvar;
		newvar++;
		i++;
	}
	while (cmd[y + ft_strlen(var) + 1])
		newcmd[i++] = cmd[(y++) + ft_strlen(var) + 1];
	newcmd[i] = '\0';
	return (newcmd);
}

char	*replace_var(char *c, char *cmd, int index)
{
	int		len;
	char	*var;
	char	*newvar;
	int		i;

	len = env_len(c);
	//printf("cmd:%s, %d, %d\n",c, len, index);
	if (!len)
		return (0);
	var = malloc((len + 1) * sizeof(char));
	if (!var)
		return (0);
	i = -1;
	while (++i < len)
	{
		var[i] = c[i];
	}
	var[i] = '\0';
	//printf("var:%s\n",var);
	newvar = ms_getenv(var);
	cmd = replcace_var_2(cmd, var, newvar, index);
	//printf("cmddd:%s\n",cmd);
	free(var);
	return (cmd);
}

char	*check_if_envvar(char *cmd)
{
	int		i;
	char	*new;

	i = -1;
	new = NULL;
	while (cmd[++i])
	{
		if (cmd[i] == '$')
		{
			if (cmd[i + 1])
				new = replace_var(&cmd[i + 1], cmd, i);
			if (new)
				cmd = new;
			//printf("new :%s\n", new);
		}
	}
	// while (*cmd)
	// {
	// 	printf("CHECK!:%s\n", cmd);
	// 	i++;
	// 	if (*cmd == '$')
	// 	{
	// 		if (*(cmd + 1))
	// 		{
	// 			new = replace_var(cmd + 1, cmd, i + len, &len);
	// 			printf("NEW:%s\n", new);
	// 			cmd = new;
	// 			cmd = cmd + len + 1;
	// 		}
	// 	}
	// 	else
	// 		cmd++;

	// }
	if (new)
	{
		//free(cmd);
		return (new);
	}
	return (cmd);
}
