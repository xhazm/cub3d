# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elenz <elenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 12:08:41 by lpfleide          #+#    #+#              #
#    Updated: 2022/04/08 15:20:34 by elenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -c -g
NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c ft_atoi_len.c ft_remalloc.c \
	ft_free2darr.c ft_btoi.c ft_striteri.c ft_str_isnum.c ft_str_is_int.c \
	ft_get_next_line.c ft_get_next_line_utils.c ft_strcmp.c
#SRC_GNL = ./gnl/get_next_line_utils.c ./gnl/get_next_line.c \
			./gnl/get_next_line_utils_bonus.c ./gnl/get_next_line_bonus.c
SRC_PRINTF = ./ft_printf/ft_printf.c ./ft_printf/ft_hex_conversions.c \
			./ft_printf/ft_helper_general.c ./ft_printf/ft_helper_width_flags.c \
			./ft_printf/ft_conversions.c
BONUS = ft_lstclear.c ft_lstdelone.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) $(SRC_PRINTF)
	ar -crs $(NAME) ft_*.o 
	ar -t $(NAME)


bonus:
	gcc $(CFLAGS) $(BONUS)
	ar -crs $(NAME) ft_*.o 
	ar -t $(NAME)

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(NAME)

re: fclean all
