CC 		= c++

CFLAGS 	= -Wall -Werror -Wextra -std=c++98

FILES 	= 	Account.cpp \
			tests.cpp

NAME 	= 	account

all 	: $(NAME)

$(NAME) : $(FILES)
	$(CC) $(CFLAGS) $^ -o $@
	./$(NAME) > output.log

clean 	:
	rm -f $(NAME)

fclean	: clean
	rm -f output.log

re 		: clean all

.PHONY 	: all clean fclean re
