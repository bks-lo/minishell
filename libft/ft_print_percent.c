/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:36:09 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:26:19 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_percent(t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dash == 1)
	{
		ft_putchar_fd('%', 1);
		index += 1;
	}
	index += ft_print_width(flags.width, 1, flags.zero);
	if (flags.dash == 0)
	{
		ft_putchar_fd('%', 1);
		index += 1;
	}
	return (index);
}
