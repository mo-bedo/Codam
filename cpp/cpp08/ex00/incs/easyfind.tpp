#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <algorithm>
#include <exception>
#include <list>

template <typename T>
size_t	easyfind(T & t, int to_find)
{
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = t.end();
	int i = 0;

	for (it = t.begin(); it != ite; it++, i++)
	{
		if (*it == to_find)
			return i;
	}
	throw std::exception();
}

#endif		// EASYFIND_TPP
