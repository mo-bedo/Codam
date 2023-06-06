#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

/*			Test 1
 *
 * 			0 1 2 3 4 5 6 7 8 9 10
 * 			1 a		d		b
 * 			2
 * 			3
 * 			4               c
 * 			5
 * 			6
 * 			7
 * 			8 e
 * 			9
 * 		   10
 *
 */

int main()
{
	{
		std::cout << "Test1" << std::endl;
		Point a (1, 1);
		Point b (8, 1);
		Point c (8, 4);

		Point d (4, 1);
		Point e (1, 8);

		if (bsp(a, b, c, d))
			std::cout << "point d is inside of triangle" << std::endl;
		else
			std::cout << "point d is outside of triangle" << std::endl;
		if (bsp(a, b, c, e))
			std::cout << "point e is inside of triangle" << std::endl;
		else
			std::cout << "point e is outside of triangle" << std::endl;
	}
	{
		std::cout << "\nTest2 " << std::endl;
		Point a (1.45f, 1.0012f);
		Point b (8.33f, 1.90f);
		Point c (8.87f, 4.62278f);

		Point d (5.0000013f, 2.1f);
		Point e (1.282f, 8.282f);

		if (bsp(a, b, c, d))
			std::cout << "point d is inside of triangle" << std::endl;
		else
			std::cout << "point d is outside of triangle" << std::endl;
		if (bsp(a, b, c, e))
			std::cout << "point e is inside of triangle" << std::endl;
		else
			std::cout << "point e is outside of triangle" << std::endl;
	}
	{
		std::cout << "\nTest3, single point triangle " << std::endl;
		Point a (1, 1);
		Point b (1, 1);
		Point c (1, 1);

		Point d (5, 2);
		Point e (1, 1);


		if (bsp(a, b, c, d))
			std::cout << "point d is inside of triangle" << std::endl;
		else
			std::cout << "point d is outside of triangle" << std::endl;
		if (bsp(a, b, c, e))
			std::cout << "point e is inside of triangle" << std::endl;
		else
			std::cout << "point e is outside of triangle" << std::endl;
	}
	return 0;
}
