SRCS = 		Bureaucrat.cpp \
			AForm.cpp \
			Intern.cpp \
			main.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp

OBJS = 		$(SRCS:.cpp=.o)

CFLAGS =	-Wall -Werror -Wextra -std=c++98

CC = 		c++

NAME =		bureaucrat

all 	: $(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.o 	: %.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean 	:
	rm -f $(OBJS)

fclean 	: clean
			rm -f $(NAME)
			rm -f *_shrubbery

re 		: fclean all

.PHONY 	: fclean re all clean
