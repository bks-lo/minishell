/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:03:27 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:38:07 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unegative_width_prec(char *uint_str, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dot >= 0)
		index += ft_print_width(flags.dot - 1, ft_strlen(uint_str) - 1, 1);
	index += ft_print_str_precision(uint_str, ft_strlen(uint_str));
	return (index);
}

static int	ft_uint_width_prec(char *uint_str, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dash == 1)
		index += ft_unegative_width_prec(uint_str, flags);
	if (flags.dot >= 0 && flags.dot < ft_strlen(uint_str))
		flags.dot = ft_strlen(uint_str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		index += ft_print_width(flags.width, 0, 0);
	}
	else
		index += ft_print_width(flags.width, ft_strlen(uint_str), flags.zero);
	if (flags.dash == 0)
		index += ft_unegative_width_prec(uint_str, flags);
	return (index);
}

int	ft_print_uint(unsigned int uint_input, t_flags flags)
{
	char	*uint_str;
	int		index;

	index = 0;
	uint_input = (unsigned int)(4294967295 + 1 + uint_input);
	if (flags.dot == 0 && uint_input == 0)
	{
		index += ft_print_width(flags.width, 0, 0);
		return (index);
	}
	uint_str = ft_utoa(uint_input);
	index += ft_uint_width_prec(uint_str, flags);
	free(uint_str);
	return (index);
}
