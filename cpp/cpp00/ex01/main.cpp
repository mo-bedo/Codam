#include "PhoneBook.hpp"
#include <string>
#include <iomanip>
#include <iostream>

int	main()
{
	PhoneBook 	book;
	int			index = 0;
	std::string option;

	std::cout << "Welcome to your PhoneBook." << std::endl;
	while (true)
	{
		std::cout << "Please enter one of the following commands: 'ADD' 'SEARCH' 'EXIT'" << std::endl;
		std::cin >> option;
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exiting" << std::endl;
			exit(1);
		}
		if (option == "ADD")
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			book.contacts[index].add(index);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (option == "SEARCH")
			book.search();
		else if (option == "EXIT")
			break ;
	}
	std::cout << "Thank you for using PhoneBook." << std::endl;
	return 0;
}
