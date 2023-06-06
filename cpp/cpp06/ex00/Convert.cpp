#include "Convert.hpp"
#include "convert_utils.hpp"
#include "limit.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

# define PRINT_SINGLE_DECIMAL_POINT true

Convert::Convert ()
{
	if (CONVERT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor Convert called." << std::endl;
}

Convert::Convert (const Convert &obj)
{
	*this = obj;
	if (CONVERT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor Convert called." << std::endl;
}

Convert::Convert (std::string input) : _input(input)
{
	if (PRINT_SINGLE_DECIMAL_POINT)
	    std::cout << std::setprecision(1) << std::fixed;
	for (int i = 0; i < 5; i++)
		this->_charIntFloatDoubleNan[i] = false;
	this->parse();
	if (CONVERT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Named constructor Convert called." << std::endl;
}

Convert& Convert::operator= (const Convert &obj)
{
	this->_input = obj._input;
	for (int i = 0; i < 5; i++)
		this->_charIntFloatDoubleNan[i] = obj._charIntFloatDoubleNan[i];
	if (CONVERT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator Convert called." << std::endl;
	return *this;
}

Convert::~Convert ()
{
	if (CONVERT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Deconstructor Convert called." << std::endl;
}

void	Convert::castChar() const
{
	std::cout << "char: " << this->_char << std::endl;
	std::cout << "int: " << static_cast<int>(this->_char) << std::endl;
	std::cout << "float: " << static_cast<float>(this->_char) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_char) << std::endl;
}

void	Convert::castInt()
{
	if (int_overflow(this->_input))
	{
		std::cout << "Integer over-/underflow! Exiting." << std::endl;
		return;
	}
	std::stringstream	ss(this->_input);

	ss >> this->_int;
	if (can_print(static_cast<long>(this->_int)))
		std::cout << "char: " << static_cast<char>(this->_int) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << this->_int << std::endl;
	std::cout << "float: " << static_cast<float>(this->_int) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_int) << std::endl;
}

void	Convert::castFloat()
{
	if (float_overflow(this->_input))
	{
		std::cout << "Float over-/underflow! Exiting." << std::endl;
		return;
	}
	this->_input[ft_strlen(this->_input) - 1] = 0;
	std::stringstream	ss (this->_input);

	ss >> this->_float;
	if (can_print(static_cast<long>(this->_float)))
		std::cout << "char: " << static_cast<char>(this->_float) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (int_cast_overflow(this->_input))
		std::cout << "int: over-/underflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->_float) << std::endl;
	std::cout << "float: " << this->_float << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_float) << std::endl;
}
void	Convert::castDouble()
{
	if (double_overflow(this->_input))
	{
		std::cout << "Double under-/overflow! Exiting." << std::endl;
		return ;
	}
	std::stringstream	ss(this->_input);

	ss >> this->_double;
	if (can_print(static_cast<long>(this->_double)))
		std::cout << "char: " << static_cast<char>(this->_double) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (int_cast_overflow(this->_input))
		std::cout << "int: under-/overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->_double) << std::endl;
	std::cout << "float: " << static_cast<double>(this->_double) << "f" << std::endl;
	std::cout << "double: " << this->_double << std::endl;
}

void	Convert::checkConversion()
{
	int	i = 0;

	while (i < 5)
	{
		if (this->_charIntFloatDoubleNan[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0 :
			castChar();
			break;
		case 1 :
			castInt();
			break;
		case 2 :
			castFloat();
			break;
		case 3 :
			castDouble();
			break;
		case 4 :
			printNan();
			return;
		default :
			std::cout << "Input not valid. Please input a single literal." << std::endl;
			break;
	}
}

void	Convert::parse()
{
	if (ft_strlen(this->_input) < 2)
	{
		this->handleSingle();
		return ;
	}
	this->removeSpaces();
	if (ft_strlen(this->_input) == 0)
	{
		std::cout << "Empty input detected. Class values not set. Exiting program." << std::endl;
		return ;
	}
	this->_charIntFloatDoubleNan[1] = is_int(this->_input);
	if (is_float(this->_input))
		this->_charIntFloatDoubleNan[2] = true;
	else if (is_double(this->_input))
		this->_charIntFloatDoubleNan[3] = true;
	else
		this->_charIntFloatDoubleNan[4] = is_nan(this->_input);
	this->checkConversion();
}

void	Convert::printNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if ((ft_strlen(this->_input) == 5) || this->_input == "nanf")
	{
		std::cout << "float: " << this->_input << std::endl;
		std::cout << "double: ";
		if (this->_input[0] == '-')
			std::cout << "-inf" << std::endl;
		else if (this->_input[0] == '+')
			std::cout << "+inf" << std::endl;
		else
			std::cout << "nan" << std::endl;
	}
	else
	{
		std::cout << "float: " << this->_input << "f" << std::endl;
		std::cout << "double: " << this->_input << std::endl;
	}
}

void	Convert::handleSingle()
{
	std::stringstream	ss;
	ss << this->_input;

	if (this->_input == "")
	{
		std::cout << "Empty input detected. Class values not set." << std::endl;
		return ;
	}
	if (is_int(this->_input))
	{
		ss >> this->_int;
		this->_charIntFloatDoubleNan[1] = true;
		castInt();
	}
	else
	{
		this->_char = this->_input[0];
		this->_charIntFloatDoubleNan[0] = true;
		castChar();
	}
}

void	Convert::removeSpaces()
{
	std::string	no_whitespace;

	for (size_t i = 0; i < ft_strlen(this->_input); i++)
	{
		if (!is_whitespace(this->_input[i]))
			no_whitespace += this->_input[i];
	}
	this->_input = no_whitespace;
}
