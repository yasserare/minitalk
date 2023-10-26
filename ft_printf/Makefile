NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
		ft_printadd.c \
		ft_printf.c \
		ft_printnumhexlow.c \
		ft_printnumhexupp.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_unsigned_dec.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re:	fclean all