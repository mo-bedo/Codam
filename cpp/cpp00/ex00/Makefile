FILES = megaphone.cpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = megaphone

all : $(NAME)

$(NAME) : $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY : re clean fclean all
