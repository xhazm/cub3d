CC = gcc
NAME = parser
FLAGS = -g  -Wall -Wextra -Werror
SRC =	./main.c \
		./parser.c \
		./check_firstrow.c \
		./check_lastrow.c \
		./check_middlerow.c \
		./check_parse.c \
		./get_info.c \
		./get_info2.c \
		./get_info3.c \
		./helpers.c \
		./read_info.c 
OBJ = $(patsubst %.c, %.o, $(SRC))

%.o : %.c $(SRC)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) ../libft/libft.a

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
