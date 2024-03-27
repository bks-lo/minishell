/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:39:46 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:34:12 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, t_flags flags)
{
	int	index;

	index = 0;
	if (flags.dash == 1)
		ft_putchar_fd(c, 1);
	index = ft_print_width(flags.width, 1, 0);
	if (flags.dash == 0)
		ft_putchar_fd(c, 1);
	return (index + 1);
}
