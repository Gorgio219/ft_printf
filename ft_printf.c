/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:02:14 by pbomber           #+#    #+#             */
/*   Updated: 2022/01/07 18:35:28 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(va_list la_vs, char str)
{
	int	count;

	count = 0;
	if (str == '%')
	{
		write(1, &str, 1);
		count++;
	}
	else if (str == 'c')
		count += ft_print_char(va_arg(la_vs, int));
	else if (str == 'd' || str == 'i')
		ft_print_int(va_arg(la_vs, int), &count);
	else if (str == 'x' || str == 'X')
		ft_print_hex(va_arg(la_vs, unsigned int), ft_base_hex(str), &count);
	else if (str == 'p')
	{
		write(1, "0x", 2);
		count += 2;
		ft_print_hex_p(va_arg(la_vs, unsigned long), &count);
	}
	else if (str == 's')
		count += ft_print_str(va_arg(la_vs, char *));
	else if (str == 'u')
		ft_print_un_int(va_arg(la_vs, unsigned int), &count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	la_vs;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(la_vs, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_parser(la_vs, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(la_vs);
	return (count);
}
