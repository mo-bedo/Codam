SRCS = 	ClapTrap.cpp \
		main.cpp

OBJS = 	$(SRCS:.cpp=.o)

CC = 	c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = 	ClapTrap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re	: fclean all

.PHONY : re fclean all clean
