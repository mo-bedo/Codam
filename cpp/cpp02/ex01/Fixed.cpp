#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_fracBits = 8;

Fixed::Fixed ()
{
	std::cout << "Default constructor called." << std::endl;

	this->_value = 0;
}

Fixed::Fixed (const Fixed & obj)
{
	std::cout << "Copy constructor called." << std::endl;

	this->_value = obj.getRawBits();
}

Fixed& Fixed::operator = (const Fixed & obj)
{
	std::cout << "Copy assignment operator called." << std::endl;

	this->_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed (const int input)
{
	std::cout << "Int constructor called." << std::endl;

	this->_value = input << _fracBits;
}

Fixed::Fixed (const float input)
{
	std::cout << "Float constructor called." << std::endl;

	this->_value = (int) (roundf (input * (1 << _fracBits)));
}

int	Fixed::getRawBits () const
{
	return (this->_value);
}

void Fixed::setRawBits (const int raw)
{
	this->_value = raw;
}

float Fixed::toFloat (void) const
{
	return ((float) this->_value / (float) (1 << _fracBits));
}

int Fixed::toInt (void) const
{
	return (this->_value >> _fracBits);
}

std::ostream& operator << (std::ostream& os, const Fixed & obj)
{
	os << obj.toFloat();
	return os;
}
