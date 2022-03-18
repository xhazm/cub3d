# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 18:59:28 by lpfleide          #+#    #+#              #
#    Updated: 2022/03/18 14:21:08 by lpfleide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d
FLAGS = -O3 -g # -Wall -Wextra -Werror
SRC = ./main.c ./user_key_input.c ./draw.c
OBJ = $(patsubst %.c, %.o, $(SRC))

%.o : %.c $(SRC)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): libmake $(OBJ)
	$(CC) $(FLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -L. libft/libft.a

libmake: mlxmake
	make all -C ./libft

mlxmake:
	make all -C ./mlx

clean:
	rm -f $(OBJ)
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make clean -C ./mlx

re: fclean all

rfast:
	rm -f $(NAME)
	rm -f $(OBJ)
	make all
	./cub3d