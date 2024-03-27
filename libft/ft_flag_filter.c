/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:16:55 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:28:28 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flag_filter(t_flags flags, va_list list)
{
	int	index;

	index = 0;
	if (flags.type == 'c')
		index = ft_print_char(va_arg(list, int), flags);
	else if (flags.type == 's')
		index += ft_print_string(va_arg(list, char *), flags);
	else if (flags.type == 'p')
		index += ft_print_pointer(va_arg(list, unsigned long long), flags);
	else if (flags.type == 'd' || flags.type == 'i')
		index += ft_print_int(va_arg(list, int), flags);
	else if (flags.type == 'u')
		index += ft_print_uint((unsigned int)va_arg(list, unsigned int), flags);
	else if (flags.type == 'x' || flags.type == 'X')
		index += ft_print_hexa(va_arg(list, unsigned int), flags);
	else if (flags.type == '%')
		index += ft_print_percent(flags);
	return (index);
}
