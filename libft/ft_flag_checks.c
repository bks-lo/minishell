/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:30:53 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:28:16 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_istype(int kar)
{
	if (kar == 'c' || kar == 's' || kar == 'p' || kar == 'd' || kar == 'i' || \
	kar == 'u' || kar == 'x' || kar == 'X' || kar == '%')
		return (1);
	return (0);
}

int	ft_isflag(int kar)
{
	if (kar == '-' || kar == '0' || kar == '.' || kar == '*')
		return (1);
	return (0);
}
