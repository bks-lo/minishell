/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:34:53 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:39:37 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dec_to_hex(unsigned long long dec, char *rtn, int size)
{
	while (dec != 0)
	{
		if ((dec % 16) < 10)
			rtn[size - 1] = (dec % 16) + 48;
		else
			rtn[size - 1] = (dec % 16) + 87;
		dec /= 16;
		size--;
	}
	return (rtn);
}

char	*ft_ptoa(unsigned long long dec)
{
	char				*rtn;
	unsigned long long	tmp;
	int					size;

	rtn = 0;
	size = 0;
	tmp = dec;
	if (dec == 0)
		return (ft_strdup("0"));
	while (tmp != 0)
	{
		tmp /= 16;
		size++;
	}
	rtn = malloc(sizeof(char) * (size + 1));
	if (!(rtn))
		return (0);
	rtn[size] = '\0';
	rtn = ft_dec_to_hex(dec, rtn, size);
	return (rtn);
}
