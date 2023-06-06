#include "Array.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
Array<T>::Array() : _size(0), _elements(nullptr)
{
	if (ARRAY_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor Array called." << std::endl;
}

template <typename T>
Array<T>::Array (unsigned int const &n) : _size(n), _elements(new T[n])
{
	if (ARRAY_PRINT_CONSTRUCTOR_MSG)
		std::cout << "N constructor Array called (negative N will be made positive)." << std::endl;
}

template <typename T>
Array<T>::Array (const Array & obj) : _size(obj.size())
{
	if (ARRAY_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor Array called." << std::endl;

	if (obj.size() > 0)
	{
		this->_elements = new T[obj.size()];
		for (std::size_t i = 0; i < obj.size(); i++)
			this->_elements[i] = obj._elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator= (const Array &obj)
{
	if (ARRAY_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator Array called." << std::endl;

	if (obj.size() > 0)
	{
		this->_elements = new T[obj.size()];
		for (std::size_t i = 0; i < obj.size(); i++)
			this->_elements[i] = obj._elements[i];
	}
	this->_size = obj.size();
	return *this;
}

template <typename T>
Array<T>::~Array ()
{
	if (ARRAY_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Deconstructor Array called." << std::endl;
	if (this->_size > 0)
		delete [] this->_elements;
}

template <typename T>
T & 		Array<T>::operator[] (std::size_t idx)
{
	if (idx >= this->size())
	{
		throw std::exception();
	}
	return this->_elements[idx];
}

template <typename T>
std::size_t	Array<T>::size() const
{
	return this->_size;
}
