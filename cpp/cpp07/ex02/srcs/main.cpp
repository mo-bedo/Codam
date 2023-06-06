#include "Array.hpp"
#include "Array.tpp"
#include <stdexcept>

int main ()
{

	// Shows copy constructor assigns new allocated space to new struct
	Array<int> int_array1(5);
	for (int i = 0; i < 5; i++)
		int_array1[i] = i * 2;
	Array<int> int_array2(int_array1);
	for (int i = 0; i < 5; i++)
		int_array1[i] = i * 3;
		
	std::cout << "int_array1 values: ";
	for (int i = 0; i < 5; i++)
		std::cout << int_array1[i] << " ";
	std::cout << "\nint_array2 values: ";
	for (int i = 0; i < 5; i++)
		std::cout << int_array2[i] << " ";
	std::cout << std::endl;

	// Same goes for assignment operator
	Array<float> float_array1(5);
	for (int i = 0; i < 5; i++)
		float_array1[i] = 1 + i;
	Array<float> float_array2 = float_array1;
	for (int i = 0; i < 5; i++)
		float_array1[i] = 5 + i;

	std::cout << "float_array1 values: ";
	for (int i = 0; i < 5; i++)
		std::cout << float_array1[i] << " ";
	std::cout << "\nfloat_array2 values: ";
	for (int i = 0; i < 5; i++)
		std::cout << float_array2[i] << " ";
	std::cout << std::endl;

	// Out of bounds access throws an exception.
	Array<float> empty_float;

	try {

		empty_float[0];
	}
	catch (std::exception &e)
	{
		std::cout << "empty_float error: " << e.what() << std::endl;
	}

	try {
		float_array1[50];
	}
	catch (std::exception & e)
	{
		std::cout << "float_array error: " << e.what() << std::endl;
	}

	try {
		int_array1[-3];
	}
	catch (std::exception & e)
	{
		std::cout << "int_array error: " << e.what() << std::endl;
	}
	return 0;
}
