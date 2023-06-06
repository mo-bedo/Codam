#include <string>
#include <iostream>

int main()
{
	std::string	brainString = "HI THIS IS BRAIN";
	std::string* stringPTR = &brainString;
	std::string& stringREF = brainString;

	std::cout << "Memory address of string variable = " << &brainString << std::endl;
	std::cout << "Memory address held by stringPTR  = " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF  = " << &stringREF << std::endl << std::endl;

	std::cout << "Value of string variable          = " << brainString << std::endl;
	std::cout << "Value where stringPTR points      = " << *stringPTR << std::endl;
	std::cout << "Value where stringREF points      = " << stringREF << std::endl;
}
