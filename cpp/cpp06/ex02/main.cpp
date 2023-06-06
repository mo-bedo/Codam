#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>

int main(void)
{
	Base *base_ptr;

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		base_ptr = generate();
		identify(base_ptr);
		identify(*base_ptr);
		std::cout << std::endl;
		delete base_ptr;
	}
	return 0;
}
