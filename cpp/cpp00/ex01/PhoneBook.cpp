#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

static void	print_columns()
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "index";
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "first name";
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "last name";
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "nickname" << std::endl;
}

void	PhoneBook::search() const
{
	int input;

	print_columns();
	for (int j = 0; j < 8; j++)
		this->contacts[j].display_all();
	std::cout << "Please input index number of contact you wish to see (0 - 7): ";
	if (!(std::cin >> input))
	{
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exiting" << std::endl;
			exit(1);
		}
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		std::cout << "Invalid input." << std::endl;
	}
	else if (input >= 0 && input <= 7)
		this->contacts[input].display_single();
	else
		std::cout << "Invalid input." << std::endl;
}
