#include "Fixed.hpp"
#include <cmath>
#include <iostream>

#define		CONSTRUCTION_PRINT	false

const int Fixed::_fracBits = 8;

Fixed::Fixed ()
{
	if (CONSTRUCTION_PRINT)
		std::cout << "Default constructor called." << std::endl;

	this->_value = 0;
}

Fixed::Fixed (const Fixed & obj)
{
	if (CONSTRUCTION_PRINT)
		std::cout << "Copy constructor called." << std::endl;

	this->_value = obj.getRawBits();
}

Fixed& Fixed::operator = (const Fixed & obj)
{
	if (CONSTRUCTION_PRINT)
		std::cout << "Copy assignment operator called." << std::endl;

	this->_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed ()
{
	if (CONSTRUCTION_PRINT)
		std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed (const int input)
{
	if (CONSTRUCTION_PRINT)
		std::cout << "Int constructor called." << std::endl;

	this->_value = input << _fracBits;
}

Fixed::Fixed (const float input)
{
	if (CONSTRUCTION_PRINT)
		std::cout << "Float constructor called." << std::endl;

	this->_value = (int) (roundf (input * (1 << _fracBits)));
}

int	Fixed::getRawBits () const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float Fixed::toFloat() const
{
	return ((float) this->_value / (float) (1 << _fracBits));
}

int Fixed::toInt() const
{
	return (this->_value >> _fracBits);
}

bool	Fixed::operator > (Fixed const & compare)
{
	return (this->_value > compare.getRawBits());
}

bool	Fixed::operator < (Fixed const & compare)
{
	return (this->_value < compare.getRawBits());
}

bool	Fixed::operator >= (Fixed const & compare)
{
	return this->_value >= compare.getRawBits();
}

bool	Fixed::operator <= (Fixed const & compare)
{
	return this->_value <= compare.getRawBits();
}

bool	Fixed::operator == (Fixed const & compare)
{
	return this->_value == compare.getRawBits();
}

bool	Fixed::operator != (Fixed const & compare)
{
	return this->_value != compare.getRawBits();
}

Fixed	Fixed::operator + (Fixed const & arithmetic)
{
	Fixed	add (this->toFloat() + arithmetic.toFloat());
	return add;
}

Fixed	Fixed::operator - (Fixed const & arithmetic)
{
	Fixed minus (this->toFloat() - arithmetic.toFloat());
	return minus;
}

Fixed	Fixed::operator * (Fixed const & arithmetic)
{
	float	math;

	math = this->toFloat() * arithmetic.toFloat();
	Fixed 	multiply (math);
	return multiply;
}

Fixed	Fixed::operator / (Fixed const & arithmetic)
{
	float	math;

	math = this->toFloat() / arithmetic.toFloat();
	Fixed divide (math);
	return divide;
}

// Pre-increment
Fixed&	Fixed::operator ++ (void)
{
	this->_value++;
	return (*this);
}

// Post-increment
Fixed	Fixed::operator ++ (int)
{
	Fixed	incr(*this);

	++this->_value;
	return (incr);
}

Fixed&	Fixed::operator -- (void)
{
	this->_value--;
	return(*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	decr(*this);

	this->_value--;
	return (decr);
}

Fixed&	Fixed::min (Fixed & a, Fixed & b)
{
	if (a > b)
		return b;
	else
		return a;
}

Fixed const&	Fixed::min (Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	else
		return a;
}

Fixed&	Fixed::max (Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed const&	Fixed::max (Fixed const & a, Fixed const & b)
{

	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

std::ostream& operator << (std::ostream & os, const Fixed & obj)
{
	os << obj.toFloat();
	return os;
}
