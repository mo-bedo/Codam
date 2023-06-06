#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private :
	int					_value;
	static const int	_fracBits;

public :
	Fixed();
	Fixed(const Fixed&);
	Fixed& operator = (const Fixed&);
	virtual ~Fixed();

	Fixed(const int);
	Fixed(const float);

	int 	getRawBits() const;
	void 	setRawBits(const int);

	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator > (Fixed const & compare);
	bool	operator < (Fixed const & compare);
	bool	operator >= (Fixed const & compare);
	bool	operator <= (Fixed const & compare);
	bool	operator == (Fixed const & compare);
	bool	operator != (Fixed const & compare);

	Fixed	operator + (Fixed const & arithmetic);
	Fixed	operator - (Fixed const & arithmetic);
	Fixed	operator * (Fixed const & arithmetic);
	Fixed	operator / (Fixed const & arithmetic);

	Fixed&	operator ++ (void);
	Fixed	operator ++ (int);
	Fixed&	operator -- (void);
	Fixed 	operator -- (int);

	static Fixed&		min(Fixed&, Fixed&);
	static Fixed const&	min(const Fixed&, const Fixed&);
	static Fixed&		max(Fixed&, Fixed&);
	static Fixed const&	max(Fixed const&, Fixed const&);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif 		// FIXED_HPP
