/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:36:24 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:34:32 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hnegative_width_prec(char *hexa, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dot >= 0)
		index += ft_print_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	index += ft_print_str_precision(hexa, ft_strlen(hexa));
	return (index);
}

static int	ft_hexa_width_prec(char *hexa, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dash == 1)
		index += ft_hnegative_width_prec(hexa, flags);
	if (flags.dot >= 0 && flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		index += ft_print_width(flags.width, 0, 0);
	}
	else
		index += ft_print_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.dash == 0)
		index += ft_hnegative_width_prec(hexa, flags);
	return (index);
}

int	ft_print_hexa(unsigned int hexa_input, t_flags flags)
{
	char	*hexa;
	int		index;
	int		sub_index;

	index = 0;
	sub_index = 0;
	hexa_input = (unsigned int)(4294967295 + 1 + hexa_input);
	if (flags.dot == 0 && hexa_input == 0)
	{
		index += ft_print_width(flags.width, 0, 0);
		return (index);
	}
	hexa = ft_ptoa((unsigned long long)hexa_input);
	if (flags.type == 'X')
	{
		while (hexa[sub_index])
		{
			hexa[sub_index] = ft_toupper(hexa[sub_index]);
			sub_index++;
		}
	}
	index += ft_hexa_width_prec(hexa, flags);
	free(hexa);
	return (index);
}
