# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 18:59:28 by lpfleide          #+#    #+#              #
#    Updated: 2022/05/02 21:24:37 by lpfleide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d
FLAGS = -O3 -g -Wall -Wextra -Werror
SRC = main.c input_keys.c input_mouse.c move.c draw_calculate.c draw_calculate_dda.c \
			draw_texture.c draw_texture_helper.c init.c init_textures.c minimap.c
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
	$(CC) $(FLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -L. libft/libft.a libparser/libparser.a

libmake: mlxmake
	make all -C ./libft
	make all -C ./libparser

mlxmake:
	make all -C ./mlx

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libparser
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libparser
	make fclean -C ./libft
	make clean -C ./mlx

re: fclean all

rfast:
	rm -f $(NAME)
	rm -f $(OBJ)
	make all
	./cub3d