/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscriabi <dscriabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:32:28 by dscriabi          #+#    #+#             */
/*   Updated: 2021/09/20 11:38:50 by dscriabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	ft_reset_flag(void)
{
	t_flags	flag;

	flag.type = 0;
	flag.width = 0;
	flag.zero = 0;
	flag.star = 0;
	flag.dash = 0;
	flag.dot = -1;
	return (flag);
}

int	ft_flag_read(va_list list, t_flags *flags, const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_istype(str[i]) && !ft_isflag(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->dash == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i += ft_interpret_dot(&str[i], flags, list);
		if (str[i] == '-')
			*flags = ft_interpret_dash(*flags);
		if (str[i] == '*')
			*flags = ft_interpret_star(list, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_interpret_digit(str[i], *flags);
		if (ft_istype(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_flags	flag_lst;
	int		index;
	int		char_count;

	index = 0;
	char_count = 0;
	flag_lst = ft_reset_flag();
	va_start(list, format);
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			index += ft_flag_read(list, &flag_lst, &format[index]);
			char_count += ft_flag_filter(flag_lst, list);
			flag_lst = ft_reset_flag();
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			char_count++;
		}
		index++;
	}
	return (char_count);
}
