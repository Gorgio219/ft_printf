/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:26:18 by pbomber           #+#    #+#             */
/*   Updated: 2022/01/07 18:15:14 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int d, char *base, int *count)
{
	int	*p_count;

	p_count = count;
	if (d >= 16)
	{
		ft_print_hex((d / 16), base, p_count);
		write(1, &base[d % 16], 1);
		*p_count = *p_count + 1;
	}
	else
	{
		write(1, &base[d], 1);
		*p_count = *p_count + 1;
	}
	return (0);
}

int	ft_print_hex_p(unsigned long d, int *count)
{
	char	*base;
	int		*p_count;

	p_count = count;
	base = "0123456789abcdef";
	if (d < 0)
		return (0);
	if (d < 16)
	{
		write(1, &base[d], 1);
		*p_count = *p_count + 1;
	}
	else
	{
		ft_print_hex_p((d / 16), p_count);
		write(1, &base[d % 16], 1);
		*p_count = *p_count + 1;
	}
	return (0);
}
