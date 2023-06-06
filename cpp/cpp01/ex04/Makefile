SRCS =		main.cpp \
			InputFile.cpp \
			NewFile.cpp \
			StringReplace.cpp

OBJS =		$(SRCS:.cpp=.o)

CC = 		c++

FLAGS =		-Wall -Werror -Wextra -std=c++98

NAME =		replace

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) *.replace

re : fclean all

.PHONY : fclean clean all re
