SRCS = 		Animal.cpp \
			Brain.cpp \
			Cat.cpp \
			Dog.cpp \
			main.cpp \
			WrongClass.cpp

OBJS =		$(SRCS:.cpp=.o)

HEADERS = 	Animal.hpp \
			Brain.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongClass.hpp

CC = 		c++

FLAGS = 	-Wall -Werror -Wextra -std=c++98 

NAME = 		animal

# Recipes

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
