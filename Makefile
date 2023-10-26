NAME = MiniTalk.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

 SRCS = client.c \
 		server.c \
 		ft_atoi.c \
   		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_printadd.c \
		./ft_printf/ft_putstr.c \
		./ft_printf/ft_printnumhexupp.c \
		./ft_printf/ft_printnumhexlow.c \
		./ft_printf/ft_unsigned_dec.c \


OBJS = ${SRCS:.c=.o}

target: server client

.SILENT:
all : ${target}

${NAME}: ${OBJS}
	ar -r ${NAME} ${OBJS}

server : ${NAME}
	$(CC) $(CFLAGS) server.c ${NAME} -o server

client : ${NAME}
	$(CC) $(CFLAGS) client.c ${NAME} -o client

clean : 
	rm -rf ${OBJS}

fclean :clean
	rm -rf ${NAME} client server

re : fclean server client
