#include "limit.hpp"
#include <limits>
#include <iostream>
#include <sstream>
#include <string>

bool	int_overflow(std::string str)
{
	std::stringstream	ss;
	long				int_lim;

	ss << str;
	ss >> int_lim;
	if (int_lim >= std::numeric_limits<int>::max() ||
		int_lim <= std::numeric_limits<int>::min() )
		return true;
	else
		return false;
}

bool	float_overflow(std::string str)
{
	std::stringstream	ss;
	double				flt_lim;

	ss << str;
	ss >> flt_lim;
	if (flt_lim == 0)
		return false;
	else if (flt_lim >= std::numeric_limits<float>::max() ||
		flt_lim <= std::numeric_limits<float>::lowest() ||
		flt_lim == std::numeric_limits<double>::infinity() ||
		flt_lim == -std::numeric_limits<double>::infinity() ||
		flt_lim == std::numeric_limits<double>::quiet_NaN() )
		return true;
	else
		return false;
}

bool	double_overflow(std::string str)
{
	std::stringstream	ss;
	long double			dbl_lim;

	ss << str;
	ss >> dbl_lim;
	if (dbl_lim == 0)
		return false;
	else if (dbl_lim >= std::numeric_limits<double>::max() ||
		dbl_lim <= (-std::numeric_limits<double>::max()) ||
		dbl_lim == std::numeric_limits<long double>::infinity() ||
		dbl_lim == -std::numeric_limits<long double>::infinity() ||
		dbl_lim == std::numeric_limits<long double>::quiet_NaN() )
		return true;
	else
		return false;
}

bool	int_cast_overflow(std::string str)
{
	std::stringstream	ss(str);
	long double			overflow;

	ss >> overflow;
	if (overflow > std::numeric_limits<int>::max() ||
		overflow < std::numeric_limits<int>::min())
		return true;
	else
		return false;
}
