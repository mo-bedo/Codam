all :	brain

brain : main.o
	c++ -Wall -Werror -Wextra -std=c++98 main.o -o brain

main.o : main.cpp
	c++ -Wall -Werror -Wextra -std=c++98 -c main.cpp -o main.o

clean :
	rm -f main.o

fclean : clean
	rm -f brain

re : fclean all

.PHONY : re fclean all clean
