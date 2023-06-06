#include "Base.hpp"

#include <cstdlib>
#include <iostream>

# define GREEN   "\e[32m"
# define YELLOW  "\e[33m"
# define BLUE    "\e[0;34m"
# define NORMAL  "\e[00m"

Base::~Base ()
{
}

Base*	generate(void)
{
	int random;
	Base *ptr;

	random = rand() % 3;
	switch (random)
	{
		case 0 :
			ptr = new A;
			std::cout << GREEN << "\tGenerated A" << NORMAL << std::endl;
			break;
		case 1 :
			ptr = new B;
			std::cout << YELLOW << "\tGenerated B" << NORMAL << std::endl;
			break;
		case 2 :
			ptr = new C;
			std::cout << BLUE << "\tGenerated C" << NORMAL << std::endl;
			break;
	}
	return ptr;
}

void	identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	std::cout << "identify by pointer:   ";
	if ((a = dynamic_cast<A*>(p)))
		std::cout << GREEN << "A" << NORMAL << std::endl;
	else if ((b = dynamic_cast<B*>(p)))
		std::cout << YELLOW << "B" << NORMAL << std::endl;
	else if ((c = dynamic_cast<C*>(p)))
		std::cout << BLUE << "C" << NORMAL << std::endl;
}

void	identify(Base& p)
{
	A a_ref;
	B b_ref;
	C c_ref;

	A& a = a_ref;
	B& b = b_ref;
	C& c = c_ref;
	std::cout << "identify by reference: ";
	try {
		a = dynamic_cast<A&>(p);
		std::cout << GREEN << "A" << NORMAL << std::endl;
	}
	catch (std::bad_cast){	}

	try {
		b = dynamic_cast<B&>(p);
		std::cout << YELLOW << "B" << NORMAL << std::endl;
	}
	catch (std::bad_cast){	}

	try {
		c = dynamic_cast<C&>(p);
		std::cout << BLUE << "C" << NORMAL << std::endl;
	}
	catch (std::bad_cast){	}
}
