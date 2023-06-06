SRCS =		main.cpp \
			Harl.cpp

OBJS =		$(SRCS:.cpp=.o)

CC = 		c++

FLAGS =		-Wall -Werror -Wextra -std=c++98

NAME =		harl

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean clean all re
