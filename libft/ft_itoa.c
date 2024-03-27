/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:18:20 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:31:07 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_for_itoa(long number)
{
	int		lenght;

	lenght = 1;
	if (number < 0)
	{
		number = number * -1;
		lenght++;
	}
	while (number > 9)
	{
		number = number / 10;
		lenght++;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	char	*return_value;
	long	number;
	int		index;

	number = n;
	index = length_for_itoa(number);
	return_value = (char *)malloc(sizeof(char) * (index + 1));
	return_value[index--] = '\0';
	if (number == 0)
	{
		return_value[0] = 48;
		return (return_value);
	}
	if (number < 0)
	{
		return_value[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		return_value[index--] = (number % 10) + 48;
		number = number / 10;
	}
	return (return_value);
}
