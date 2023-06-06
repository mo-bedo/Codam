#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private :
	int					_value;
	static const int	_bits;
public :
	Fixed ();
	Fixed (const Fixed & obj);
	Fixed & operator = (const Fixed & obj);
	virtual ~Fixed();

	int 	getRawBits (void) const;
	void	setRawBits (int const raw);
};

#endif  	// FIXED_HPP
