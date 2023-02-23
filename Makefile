# $(NAME), all, clean, fclean y re

LIB = ar rcs
RM = rm -f

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = printf.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_itohex.c ft_hex_print.c ft_decimal.c

OBJ = $(SRC:.c=.o)
INCLUDE = printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ) $(INCLUDE)

clean:
	$(LIB) $(NAME) $(OBJ) $(INCLUDE)

fclean: clean
	$(RM) $(NAME)

re: fclean

.PHONY: all clean fclean re
