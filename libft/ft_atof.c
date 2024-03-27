/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:07:44 by rponsonn          #+#    #+#             */
/*   Updated: 2022/03/07 16:31:42 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**basic atof that converts generic 123.4567 into a double
**doesn't take into account uses of 1.2e-10
*/
typedef struct s_var
{
	double	num;
	int		exponent;
	int		i;
	int		negative;
}			t_var;

double	ft_atof(const char *str)
{
	t_var	var;

	var.i = 0;
	var.num = 0.0;
	var.exponent = 0;
	var.negative = 0;
	if (str[var.i] == '-')
		var.negative = ++var.i;
	while (str[var.i] && ft_isdigit(str[var.i]))
		var.num = var.num * 10.0 + (str[var.i++] - '0');
	if (str[var.i] == '.')
	{
		var.i++;
		while (str[var.i] && ft_isdigit(str[var.i]))
		{
			var.num = var.num * 10.0 + (str[var.i++] - '0');
			var.exponent--;
		}
	}
	while (var.exponent++ < 0)
		var.num /= 10;
	if (var.negative)
		var.num = -var.num;
	return (var.num);
}
