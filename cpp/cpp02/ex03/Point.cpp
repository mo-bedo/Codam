#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(float setX, float setY) : _x(Fixed(setX)), _y(Fixed(setY))
{
}

Point::Point(const Point& op) : _x(Fixed(op._x)), _y(Fixed(op._y))
{
}

Point& Point::operator = (const Point& op)
{
	(void) op;
	std::cout << "Copy assignment called for const values! x and y values will not be set!!" << std::endl;
	return *this;
}

Point::~Point()
{
}

float Point::getXfloat () const
{
	return this->_x.toFloat();
}

float Point::getYfloat () const
{
	return this->_y.toFloat();
}

bool	Point::operator== (const Point & obj) const
{
	if ((this->getYfloat() == obj.getYfloat()) &&
		 this->getXfloat() == obj.getXfloat())
		return true;
	else
		return false;
}
