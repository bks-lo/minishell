/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoutofintrange.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:55:05 by dscriabi          #+#    #+#             */
/*   Updated: 2021/11/03 18:05:08 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isoutofintrange(char *number)
{
	int	i;
	int	is_neg;

	i = 0;
	while (number[i])
	{
		if ((number[i] > '9' || number[i] < '0') && \
		number[i] != '-' && number[i] != '+')
			return (-1);
		i++;
	}
	i = 0;
	is_neg = (number[0] == '-');
	while (number[i] < '1' || number[i] > '9')
		i++;
	if ((ft_strlen(number + i) > 9 && number[i] > '2') \
	|| ft_strlen(number + i) > 10)
		return (1);
	if ((ft_atoi(number) < 0 && is_neg == 0) || \
	(ft_atoi(number) > 0 && is_neg == 1))
		return (1);
	return (0);
}
