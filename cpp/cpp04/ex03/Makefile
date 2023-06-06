SRCS = 	AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		main.cpp \
		MateriaSource.cpp

OBJS = 	$(SRCS:.cpp=.o)

CC = 	c++

FLAGS =	-Wall -Werror -Wextra -std=c++98

DEBUG = debug

NAME = 	materia

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(DEBUG) : fclean
	$(CC) $(SRCS) -g -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(DEBUG)

re : fclean all

.PHONY : all clean fclean re

