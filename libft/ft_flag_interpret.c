/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_interpret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:10:33 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:28:44 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_interpret_dot(const char *str, t_flags *flags, va_list list)
{
	int	index;

	index = 0;
	index++;
	if (str[index] == '*')
	{
		flags->dot = va_arg(list, int);
		index++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[index]))
			flags->dot = (flags->dot * 10) + (str[index++] - '0');
	}
	return (index);
}

t_flags	ft_interpret_dash(t_flags flags)
{
	flags.dash = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_interpret_star(va_list list, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(list, int);
	if (flags.width < 0)
	{
		flags.dash = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

t_flags	ft_interpret_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
