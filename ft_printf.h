/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:01:47 by pbomber           #+#    #+#             */
/*   Updated: 2022/01/07 18:27:19 by pbomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_un_int(unsigned int d, int *count);
int		ft_print_int(int d, int *count);
int		ft_print_hex(unsigned int d, char *base, int *count);
int		ft_print_hex_p(unsigned long d, int *count);
char	*ft_base_hex(char c);
int		ft_neg_int(int *d);

#endif