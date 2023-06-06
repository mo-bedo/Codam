#include "Convert.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Program needs 1 parameter (no more, no less)." << std::endl;
		return 1;
	}
	std::string input (argv[1]);

	Convert a(input);
	return 0;
}
