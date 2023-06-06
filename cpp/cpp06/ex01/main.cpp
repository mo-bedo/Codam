#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t > (ptr);
}

Data*		deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*> (raw);
}

int main (void)
{
	Data 		shortString;
	Data		longString;
	Data 		*testPtr;
	uintptr_t	test;

	shortString.i = 1111;
	shortString.c = 'S';
	shortString.str = "short";

	longString.i = 8888;
	longString.c = 'L';
	longString.str = "longer then the short string";

	test = serialize(&shortString);
	testPtr = deserialize(test);
	std::cout << "Next prints should be the same : " << std::endl;
	std::cout << test << std::endl;
	std::cout << serialize(testPtr) << std::endl << std::endl;

	std::cout << "Printing values of Data struct pointed to by testPtr: " << std::endl;
	std::cout << testPtr->i << std::endl;
	std::cout << testPtr->c << std::endl;
	std::cout << testPtr->str << std::endl << std::endl;;

	test = serialize(&longString);
	testPtr = deserialize(test);
	std::cout << "Again, next prints should be the same (but differ from those above): " << std::endl;
	std::cout << test << std::endl;
	std::cout << serialize(testPtr) << std::endl << std::endl;

	std::cout << "Printing values of Data struct pointed to by testPtr:" << std::endl;
	std::cout << testPtr->i << std::endl;
	std::cout << testPtr->c << std::endl;
	std::cout << testPtr->str << std::endl;

	return 0;
}
