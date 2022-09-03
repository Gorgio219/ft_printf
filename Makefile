# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbomber <pbomber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 18:06:53 by pbomber           #+#    #+#              #
#    Updated: 2022/01/07 18:08:12 by pbomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c ft_printf_utilits.c ft_printf_int.c ft_printf_hex.c ft_printf_char.c

OBJS = $(LIST:.c=.o)

HEADER = ft_printf.h

MAKEFILE = Makefile

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $?

%.o : %.c	$(HEADER) $(MAKEFILE)
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
