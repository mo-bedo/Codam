SRC		=	bsp.cpp \
			Fixed.cpp \
			main.cpp \
			Point.cpp

CC		= c++

OBJ		= $(SRC:.cpp=.o)

FLAGS	= -Wall -Werror -Wextra -std=c++98

NAME 	= bsp

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all
