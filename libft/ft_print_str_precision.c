/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:19:22 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:26:12 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str_precision(char *str, int precision)
{
	int	index;

	index = 0;
	while (str[index] && index < precision)
	{
		ft_putchar_fd(str[index], 1);
		index++;
	}
	return (index);
}
