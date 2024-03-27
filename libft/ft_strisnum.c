/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitriscr <dimitriscr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:31:46 by dimitriscr        #+#    #+#             */
/*   Updated: 2022/02/17 17:31:47 by dimitriscr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnum(const char *str)
{
	int	i;
	int	symflag;

	i = 1;
	symflag = 0;
	if (!str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
		symflag = 1;
	if (!(str[0] == '+' || str[0] == '-' || ft_isdigit(str[0])))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (symflag && i == 1)
		return (0);
	else
		return (1);
}
