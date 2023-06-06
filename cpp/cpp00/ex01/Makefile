CC 		= c++

CFLAGS 	= -Wall -Werror -Wextra -std=c++98

FILES 	= 	Contact.cpp \
			PhoneBook.cpp \
			main.cpp

NAME 	= phonebook

all 	: $(NAME)

$(NAME) : $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean 	:
	rm -f $(NAME)

fclean	: clean

re 		: fclean all

.PHONY 	: all clean fclean re
