#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_bits = 8;

Fixed::Fixed ()
{
	std::cout << "Fixed: default constructor called." << std::endl;

	this->_value = 0;
}

Fixed::Fixed (const Fixed & obj)
{
	std::cout << "Fixed: copy constructor called." << std::endl;

	this->_value = obj.getRawBits();
}

Fixed& Fixed::operator = (const Fixed & obj)
{
	std::cout << "Fixed: copy assignment operator called." << std::endl;

	this->_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed ()
{
	std::cout << "Fixed: destructor called." << std::endl;
}

int		Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called." << std::endl;

	return (this->_value);
}

void	Fixed::setRawBits (const int raw)
{
	std::cout << "setRawBits member function called." << std::endl;

	this->_value = raw;
}
