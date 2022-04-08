# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elenz <elenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 18:59:28 by lpfleide          #+#    #+#              #
#    Updated: 2022/04/08 21:58:31 by elenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d
FLAGS = -O3 -g # -Wall -Wextra -Werror
SRC = main.c user_key_input.c draw.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
SRC_DIR = ./src/
OBJ_DIR = ./obj/

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

all: obj $(NAME)

obj: 
	mkdir -p $(OBJ_DIR)
	
$(NAME): libmake $(OBJ)
	$(CC) $(FLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -L. libft/libft.a libparser/parser.a

libmake: mlxmake
	make all -C ./libft
	make all -C ./libparser

mlxmake:
	make all -C ./mlx

clean:
	rm -rf $(OBJ_DIR)
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