/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:17:15 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:35:53 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_width_prec(char *ptr, t_flags flags)
{
	int	index;

	index = 2;
	ft_putstr_fd("0x", 1);
	if (flags.dot >= 0)
	{
		index += ft_print_width(flags.dot, ft_strlen(ptr), 1);
		index += ft_print_str_precision(ptr, flags.dot);
	}
	else
	{
		ft_putstr_fd(ptr, 1);
		index += ft_strlen(ptr);
	}
	return (index);
}

int	ft_print_pointer(unsigned long long ull_ptr, t_flags flags)
{
	char	*ptr;
	int		index;

	index = 0;
	if (ull_ptr == 0 && flags.dot == 0)
	{
		index += 2;
		if (flags.dash)
			ft_putstr_fd("0x", 1);
		index += ft_print_width(flags.width, 2, flags.zero);
		if (!flags.dash)
			ft_putstr_fd("0x", 1);
		return (index);
	}
	ptr = ft_ptoa(ull_ptr);
	if (flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.dash == 1)
		index += ft_ptr_width_prec(ptr, flags);
	index += ft_print_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.dash == 0)
		index += ft_ptr_width_prec(ptr, flags);
	free(ptr);
	return (index);
}
