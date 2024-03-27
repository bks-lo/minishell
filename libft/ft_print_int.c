/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimitriscr <dimitriscr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:23:44 by marvin            #+#    #+#             */
/*   Updated: 2022/02/17 17:31:33 by dimitriscr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative_width_prec(char *int_str, int integer, t_flags flags)
{
	int	index;

	index = 0;
	if (integer < 0 && flags.dot >= 0)
		ft_putchar_fd('-', 1);
	if (flags.dot >= 0)
		index += ft_print_width(flags.dot - 1, ft_strlen(int_str) - 1, 1);
	index += ft_print_str_precision(int_str, ft_strlen(int_str));
	return (index);
}

static int	ft_int_width_prec(char *int_str, int integer, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dash == 1)
		index += ft_negative_width_prec(int_str, integer, flags);
	if (flags.dot >= 0 && flags.dot < ft_strlen(int_str))
		flags.dot = ft_strlen(int_str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		index += ft_print_width(flags.width, 0, 0);
	}
	else
		index += ft_print_width(flags.width, ft_strlen(int_str), flags.zero);
	if (flags.dash == 0)
		index += ft_negative_width_prec(int_str, integer, flags);
	return (index);
}

static int	ft_print_int_help(int i, int i_i, int reverse, t_flags flags)
{
	char	*int_str;
	int		index;

	index = 0;
	if (reverse && i_i == -2147483648)
	{
		int_str = ft_strdup("2147483648");
	}
	else if (reverse)
	{
		i_i *= -1;
		int_str = ft_itoa(i_i);
	}
	else
		int_str = ft_itoa(i_i);
	index += ft_int_width_prec(int_str, i, flags);
	free(int_str);
	return (index);
}

int	ft_print_int(int integer_input, t_flags flags)
{
	int		integer;
	int		index;
	int		reverse;

	reverse = 0;
	integer = integer_input;
	index = 0;
	if (flags.dot == 0 && integer_input == 0)
	{
		index += ft_print_width(flags.width, 0, 0);
		return (index);
	}
	if (integer_input < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot <= -1)
			ft_putchar_fd('-', 1);
		reverse = 1;
		flags.zero = 1;
		flags.width--;
		index++;
	}
	index += ft_print_int_help(integer, integer_input, reverse, flags);
	return (index);
}
