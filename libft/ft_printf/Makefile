# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 16:43:08 by lpfleide          #+#    #+#              #
#    Updated: 2021/12/15 17:18:24 by lpfleide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -c
NAME = libftprintf.a
SRC = ft_printf.c ft_conversions.c ft_hex_conversions.c ft_helper_width_flags.c \
		ft_helper_general.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC)
	ar -crs $(NAME) ft_*.o
	ar -t $(NAME)
	
	
clean:
	rm -f *.o *~

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)
