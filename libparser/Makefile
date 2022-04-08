CFLAGS = -Wall -Werror -Wextra -c -g
NAME = parser.a
SRC =	./parser.c \
		./check_firstrow.c \
		./check_lastrow.c \
		./check_middlerow.c \
		./check_parse.c \
		./get_info.c \
		./get_info2.c \
		./get_info3.c \
		./helpers.c \
		./read_info.c \
		./get_doors.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) $(SRC_PRINTF)
	ar -crs $(NAME) *.o 
	ar -t $(NAME)


clean:
	rm -f *.o *~

fclean: clean
	rm -f $(NAME)

re: fclean all
