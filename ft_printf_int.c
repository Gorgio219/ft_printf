/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:22:18 by pbomber           #+#    #+#             */
/*   Updated: 2022/01/07 18:27:51 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_un_int(unsigned int d, int *count)
{
	int		*p_count;
	char	ch;

	p_count = count;
	if (d >= 10)
	{
		ch = '0' + (d % 10);
		ft_print_un_int((d / 10), p_count);
		write(1, &ch, 1);
		*p_count = *p_count + 1;
	}
	else
	{
		ch = '0' + d;
		write(1, &ch, 1);
		*p_count = *p_count + 1;
	}
	return (0);
}

int	ft_print_int(int d, int *count)
{
	char	ch;
	int		*p_count;

	p_count = count;
	if (d == -2147483648)
	{
		*p_count = write(1, "-2147483648", 11);
		return (0);
	}
	if (d < 0)
		*p_count = ft_neg_int(&d);
	if (d >= 10)
	{
		ch = '0' + (d % 10);
		ft_print_int((d / 10), p_count);
		write(1, &ch, 1);
		*p_count = *p_count + 1;
	}
	else
	{
		ch = '0' + d;
		write(1, &ch, 1);
		*p_count = *p_count + 1;
	}
	return (0);
}
