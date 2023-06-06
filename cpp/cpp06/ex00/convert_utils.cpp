#include "convert_utils.hpp"
#include <string>

static bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(std::string str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return i;
}

bool	is_double(std::string str)
{
	size_t	i = 0;
	bool	digit_char = false;
	bool	point_char = false;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < ft_strlen(str))
	{
		if (is_digit(str[i]))
		{
			digit_char = true;
			i++;
		}
		else if (str[i] == '.' && !point_char)
		{
			point_char = true;
			i++;
		}
		else
			return false;
	}
	return true;
}

bool	is_float(std::string str)
{
	if (str[ft_strlen(str) - 1] == 'f')
	{
		str[ft_strlen(str) - 1] = 0;
		return is_double(str);
	}
	else
		return false;
}

bool	is_int(std::string str)
{
	size_t	i = 0;

	if ((str[i] == '-' || str[i] == '+') && str[1])
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == ft_strlen(str))
		return true;
	else
		return false;
}

bool	is_nan(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" ||
		str == "nan" || str == "+inf" || str == "-inf" || 
		str == "inf" || str == "inff")
		return true;
	else
		return false;
}

bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v' );
}

bool	can_print(long c)
{
	return (c >= 32 && c <= 126);
}
