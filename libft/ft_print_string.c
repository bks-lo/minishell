/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:55:00 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:37:47 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_width_prec(char *str, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dot >= 0)
	{
		index += ft_print_width(flags.dot, ft_strlen(str), 0);
		index += ft_print_str_precision(str, flags.dot);
	}
	else
	{
		index += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (index);
}

int	ft_print_string(char *str, t_flags flags)
{
	int	index;

	index = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dash == 1)
		index += ft_str_width_prec(str, flags);
	if (flags.dot >= 0)
		index += ft_print_width(flags.width, flags.dot, 0);
	else
		index += ft_print_width(flags.width, ft_strlen(str), 0);
	if (flags.dash == 0)
		index += ft_str_width_prec(str, flags);
	return (index);
}
