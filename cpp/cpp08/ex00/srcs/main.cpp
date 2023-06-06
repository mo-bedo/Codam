#include "easyfind.hpp"
#include "easyfind.tpp"
#include <iostream>
#include <list>

int main ()
{
	std::list<int> lijst;

	lijst.push_back(11);
	lijst.push_back(22);
	lijst.push_back(33);
	lijst.push_back(25);
	lijst.push_back(-44);
	lijst.push_back(55);
	lijst.push_back(25);
	lijst.push_back(-125);
	lijst.push_back(225);
	lijst.push_back(425);

	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = lijst.end();

	std::cout << "Printing list positions with values" << std::endl;
	std::cout << std::endl << "Position:";
	for (int i = 0; i < 10; i++)
		std::cout << "\t" << i;
	std::cout << std::endl << "Value:   ";	
	for (it = lijst.begin(); it != ite; it++)
	{
		std::cout << "\t" << *it;
	}
	std::cout << std::endl << std::endl;;	

	try
	{
		std::cout << "Position of first 25 in list: ";
		std::cout << easyfind(lijst, 25) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "easyfind no occurence: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Position of first 425 in list: ";
		std::cout << easyfind(lijst, 425) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "easyfind no occurence: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Position of first 21 in list: ";
		std::cout << easyfind(lijst, 21) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "easyfind no occurence: " << e.what() << std::endl;
	}
	return 0;
}
