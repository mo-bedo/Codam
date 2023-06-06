#include "Fixed.hpp"
#include <iostream>

int main()
{
	// Since min / max are static function you can call them without
	// any constructed Fixed class.
	{
		const int a = 3;
		const int b = 4;
		std::cout << "Static min / max : " << std::endl;
		std::cout << "max(3, 4) = " << Fixed::max(a, b) << std::endl;
		std::cout << "min(19.0f, 17) = " << Fixed::min(19.0f, 17) << std::endl << std::endl;
	}

	std::cout << "Required by subject : " << std::endl;

	Fixed 		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "\nTester: " << std::endl;

	a--;
	a--;
	std::cout << "a after 2 decrements: " << a << std::endl << std::endl;

	Fixed e(Fixed(3) * Fixed(4));
	Fixed f(Fixed(21) / Fixed(4));
	Fixed g(Fixed(1255) - Fixed(999));
	Fixed g1(Fixed(14) + Fixed(13));

	std::cout << "Fixed e(Fixed(3) * Fixed(4)) = " << e << std::endl;
	std::cout << "Fixed f(Fixed(21) / Fixed(4)) = " << f << std::endl;
	std::cout << "Fixed g(Fixed(1255) - Fixed(999)) = " << g << std::endl;
	std::cout << "Fixed g1(Fixed(14) + Fixed(13)) = " << g1 << std::endl << std::endl;

	Fixed h(Fixed(12.75f) * Fixed(3));
	Fixed i(Fixed(12) * Fixed(13));
	Fixed j(Fixed(1) / Fixed(256));

	std::cout << "Fixed h(Fixed(12.75f) * Fixed(3)) = " << h << std::endl;
	std::cout << "Fixed i(Fixed(12) * Fixed(13)) = " << i << std::endl;
	std::cout << "Fixed j(Fixed(1) / Fixed(256)) = " << j << std::endl << std::endl;

	std::cout << "Comparing operators : " << std::endl;

	Fixed number (11);

	if (Fixed(12) > number)
		std::cout << "12 > " << number << std::endl;
	else
		std::cout << "12 !> " << number << std::endl;

	if (Fixed(12) < number)
		std::cout << "12 < " << number << std::endl;
	else
		std::cout << "12 !< " << number << std::endl;

	if (Fixed(12) >= number)
		std::cout << "12 >= " << number << std::endl;
	else
		std::cout << "12 !(>=) " << number << std::endl;

	if (Fixed(12) <= number)
		std::cout << "12 <= " << number << std::endl;
	else
		std::cout << "12 !(<=) " << number << std::endl;

	if (Fixed(12) == number)
		std::cout << "12 == " << number << std::endl;
	else
		std::cout << "12 !(==) " << number << std::endl;

	if (Fixed(12) != number)
		std::cout << "12 != " << number << std::endl;
	else
		std::cout << "12 !(!=) " << number << std::endl;
	return 0;
}
