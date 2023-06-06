SRCS = ft_printf.c hexa.c itoa.c uitoa.c

OBJS = $(SRCS:.c=.o)

HEADERFILE := ft_printf.h

CFLAGS = -Wall -Werror -Wextra

CC = gcc

NAME := libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -ru $(NAME) $^

%.o : %.c $(HEADERFILE)
	$(CC) -c $(CFLAGS) -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
