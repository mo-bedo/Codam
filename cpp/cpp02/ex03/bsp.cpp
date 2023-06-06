#include "Point.hpp"

static bool	is_single_point_triangle(Point a, Point b, Point c)
{
	if (a == b && a == c)
		return true;
	else
		return false;
}

// Looks where p1 is in ref to the line p2-p3.
static float is_left_or_right_of_point (Point p1, Point p2, Point p3)
{
	return (p1.getXfloat() - p3.getXfloat()) * (p2.getYfloat() - p3.getYfloat())
		- (p2.getXfloat() - p3.getXfloat()) * (p1.getYfloat() - p3.getYfloat());
}

// Function checks if point is either on the left or right side
// of AB BC and CA, if so it's inside the triangle.
// If is_left or is_right is false it means that all 3 OR's are false.
// Meaning that for the opposite side all must be true. So point is in triangle.
bool	bsp (Point const a, Point const b, Point const c, Point const point)
{
	bool 	is_left, is_right;
	float	p_AB, p_BC, p_CA;

	if (is_single_point_triangle(a, b, c))
	{
		if (a == point)
			return true;
		else
			return false;
	}

	p_AB = is_left_or_right_of_point(point, a, b);
	p_BC = is_left_or_right_of_point(point, b, c);
	p_CA = is_left_or_right_of_point(point, c, a);

	is_left = (p_AB < 0) || (p_BC < 0) || (p_CA < 0);
	is_right = (p_AB > 0) || (p_BC > 0) || (p_CA > 0);

	return !(is_left && is_right);
}
