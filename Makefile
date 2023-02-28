LIB = ar rcs
RM = rm -f

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = printf.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_itohex.c ft_hex_print.c ft_hex_print_void.c\
ft_ptrtohex.c ft_strlen.c ft_itoa.c ft_print_utoa.c

OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ) $(INCLUDE)

compile:
	$(CC) $(FLAGS) main.c -L. -lftprintf

test: re compile

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
