#ifndef	POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point {
private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point ();
	Point (float, float);
	Point(const Point&);
	Point& operator = (const Point&);
	virtual ~Point();

	float getXfloat () const;
	float getYfloat () const;

	bool operator == (Point const &) const;
};

bool bsp(Point, Point, Point, Point);

#endif  // POINT_HPP
