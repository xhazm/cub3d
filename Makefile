# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 18:59:28 by lpfleide          #+#    #+#              #
#    Updated: 2022/04/07 13:53:23 by lpfleide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d
FLAGS = -O3 -g # -Wall -Wextra -Werror
SRC = main.c user_key_input.c move.c draw.c textures.c initialization.c\
	../libparser/check_firstrow.c ../libparser/check_lastrow.c ../libparser/check_middlerow.c \
	../libparser/check_parse.c ../libparser/get_doors.c ../libparser/get_info.c ../libparser/get_info2.c \
	../libparser/get_info3.c ../libparser/helpers.c ../libparser/parser.c ../libparser/read_info.c
OBJ_FILES = $(patsubst %.c, %.o, $(SRC))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
SRC_DIR = ./src/
OBJ_DIR = ./obj/

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all: obj $(NAME)

obj: 
	mkdir -p $(OBJ_DIR)
	
$(NAME): libmake $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Imlx_linux -L./mlx_linux -lmlx_Linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) -L. libft/libft.a

libmake: mlxmake
	make all -C ./libft

mlxmake:
	make all -C ./mlx_linux

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft
	make clean -C ./mlx_linux

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make fclean -C ./libparser
	make clean -C ./mlx_linux

re: fclean all

rfast:
	rm -f $(NAME)
	rm -f $(OBJ)
	make all