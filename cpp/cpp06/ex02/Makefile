SRCS = 		main.cpp \
			Base.cpp

OBJS = 		$(SRCS:.cpp=.o)

CFLAGS =	-Wall -Werror -Wextra -std=c++98

CC = 		c++

NAME =		base

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean re all clean
