#include "Span.hpp"
#include <iostream>

#include <algorithm>

Span::Span () : _maxInts()
{
	if (SPAN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor Span called." << std::endl;
}

Span::Span (unsigned const & N) : _maxInts(N)
{
	if (SPAN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "N constructor Span called." << std::endl;
}


Span::Span (const Span &obj) : _maxInts(obj._maxInts)
{
	if (SPAN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor Span called." << std::endl;
}

Span& Span::operator= (const Span &obj)
{
	(void) obj;
	if (SPAN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator Span called." << std::endl;
	return *this;
}

Span::~Span ()
{
	if (SPAN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Destructor Span called." << std::endl;
}

void		Span::addNumber(int add)
{
	if (this->_storedInts.capacity() >= this->_maxInts)
		throw SpanFull();
	this->_storedInts.push_back(add);
}

void		Span::addRange(std::vector<int> range_to_insert)
{
	this->_storedInts.insert(this->_storedInts.end(),
				 range_to_insert.begin(), range_to_insert.end());
}

long		Span::longestSpan()
{
	if (this->_storedInts.size() <= 1)
		throw NoSpanFound();
	long	min_val;
	long 	max_val;

	max_val = * std::max_element (this->_storedInts.begin(), this->_storedInts.end());
	min_val = * std::min_element (this->_storedInts.begin(), this->_storedInts.end());
	return max_val - min_val;
}

long		Span::shortestSpan()
{
	if (this->_storedInts.size() <= 1)
		throw NoSpanFound();
	std::vector<int>::iterator it = this->_storedInts.begin();
	std::vector<int>::iterator ite = this->_storedInts.end();
	std::sort(it, ite);

	long	diff = static_cast<long>(*(it + 1)) - static_cast<long>(*it);
	long	next_diff;
	for (it++; it + 1 != ite; it++)
	{
		next_diff = static_cast<long>(*(it + 1)) - static_cast<long>(*it);
		if (diff > next_diff)
			diff = next_diff;
	}
	return diff;
}

void		Span::printInt() const
{
	if (this->_storedInts.size() <= 1)
		throw NoSpanFound();

	std::vector<int>::const_iterator it ;
	std::vector<int>::const_iterator ite = this->_storedInts.end();



	for (it = this->_storedInts.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

const char*	Span::NoSpanFound::what() const throw()
{
	return "No Span found (not enough integers in container).";
}


const char*	Span::SpanFull::what() const throw()
{
	return "Span container is full.";
}

