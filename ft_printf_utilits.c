/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:32:50 by pbomber           #+#    #+#             */
/*   Updated: 2022/01/06 22:38:29 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_neg_int(int *d)
{
	int	*p_d;

	p_d = d;
	if (*d < 0)
	{
		write(1, "-", 1);
		*p_d = *p_d * (-1);
		return (1);
	}
	return (0);
}

char	*ft_base_hex(char c)
{	
	if (c == 'x')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}
