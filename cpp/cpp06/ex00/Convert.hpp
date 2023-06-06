#ifndef CONVERT_HHP
# define CONVERT_HHP

# define CONVERT_PRINT_CONSTRUCTOR_MSG	false

#include <string>

class Convert
{
private :
	std::string	_input;

	char	_char;
	int 	_int;
	float	_float;
	double	_double;
	bool	_charIntFloatDoubleNan[5];

	void	castChar() const;
	void	castInt() ;
	void	castFloat();
	void	castDouble();

	void	checkConversion();
	void	handleSingle();
	void	parse();
	void	printNan();
	void	removeSpaces();

public :
	Convert ();
	Convert (std::string );
	Convert (const Convert &);
	Convert &operator= (const Convert &);
	~Convert ();
};

#endif //		CONVERT_HHP
