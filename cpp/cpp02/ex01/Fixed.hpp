#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private :
	int					_value;
	static const int	_fracBits;

public :
	Fixed ();
	Fixed (const Fixed &);
	Fixed& operator = (const Fixed &);
	virtual ~Fixed ();

	Fixed (const int);
	Fixed (const float);

	int 	getRawBits () const;
	void 	setRawBits (const int);

	float	toFloat (void) const;
	int		toInt (void) const;
};

std::ostream& operator << (std::ostream& os, const Fixed& obj);

#endif 		// FIXED_HPP
