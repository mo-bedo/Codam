SRCS = 	error.c push_swap_utils.c main.c sorter_functions.c radix.c \
		doubly_linked_list.c ft_split.c push_swap_utils_2.c \
		sort_three_five.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean