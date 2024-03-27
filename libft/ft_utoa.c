/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:24:49 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:45:34 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_utoa_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 1)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char	*ft_utoa_help(char *rtn, long nbr, int len)
{
	int	negative;

	negative = 0;
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (negative)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;

	nbr = n;
	len = ft_utoa_size(nbr);
	rtn = 0;
	rtn = ft_utoa_help(rtn, nbr, len);
	if (!(rtn))
		return (0);
	return (rtn);
}
