/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:08:52 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:27:11 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nitems, int size)
{
	char			*return_value;
	unsigned int	total_size;
	unsigned int	index;

	total_size = nitems * size;
	return_value = malloc(total_size);
	if (!(return_value))
		return (NULL);
	index = 0;
	while (total_size != 0)
	{
		return_value[index] = 0;
		index++;
		total_size--;
	}
	return ((void *)return_value);
}
