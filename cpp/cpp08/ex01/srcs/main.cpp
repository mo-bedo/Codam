#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iostream>

int main ()
{
	srand(time(NULL));

	std::cout << "Mandatory part: " << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "All zero's: " << std::endl;
	Span a (5);
	a.addNumber(0);
	a.addNumber(0);
	a.addNumber(0);
	a.addNumber(0);
	a.addNumber(0);
	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "10000 numbers: " << std::endl;
	std::vector<int> 	manyNb;
	Span 				b(45);
	manyNb.reserve(10000);
	for (int i = 0; i < 10000; i++)
	{
		if (i % 2)
			manyNb.push_back(rand());
		else
			manyNb.push_back(- rand());
	}
	b.addRange(manyNb);
	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "int min, min: " << std::endl;
	Span c(2);
	c.addNumber(INT_MIN);
	c.addNumber(INT_MIN);
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "int min, max: " << std::endl;
	Span c1(2);
	c1.addNumber(INT_MAX);
	c1.addNumber(INT_MIN);
	std::cout << c1.shortestSpan() << std::endl;
	std::cout << c1.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "int min, min, max: " << std::endl;
	Span d(3);
	d.addNumber(INT_MAX);
	d.addNumber(INT_MIN);
	d.addNumber(INT_MIN);
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "Exceptions: " << std::endl;
	try
	{
		Span e(0);
		e.addNumber(1);
	}
	catch (std::exception &excep)
	{
		std::cout << excep.what() << std::endl;
	}
	try
	{
		Span e(1);
		e.addNumber(342);
		e.shortestSpan();
	}
	catch (std::exception &excep)
	{
		std::cout << excep.what() << std::endl;
	}
	try
	{
		Span e(1);
		e.addNumber(342);
		e.longestSpan();
	}
	catch (std::exception &excep)
	{
		std::cout << excep.what() << std::endl;
	}
	return 0;
}
