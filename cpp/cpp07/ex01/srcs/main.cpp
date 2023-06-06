#include "iter.hpp"
#include <iostream>
#include <string>

struct Astruct {
	int	value;
	int structIdx;
};

template <typename T>
void print_func(T & array )
{
	std::cout << array << " ";
}

template <typename T>
void add(T & input)
{
	input++;
}

void	set_struct_value(Astruct &input)
{
	static int struct_idx = 0;
	static int x = 2;

	input.structIdx = struct_idx++;
	input.value = x;
	x *= 2;
}

void	print_struct(Astruct &input)
{
	std::cout << "Struct[" << input.structIdx << "] has value " << input.value << std::endl;
}

int main ()
{
		//  Char string  
	char 	char_str[7] = "aaabbb";
	std::cout << "\tchar_str " << std::endl;
	iter (char_str, 6, print_func<char>);
	std::cout << std::endl;
	iter (char_str, 6, add<char>);
	std::cout << "char_str after iter(add) is called):" << std::endl;
	iter (char_str, 6, print_func<char>);
	std::cout << std::endl << std::endl;

 	 	//  Int array
	int 	int_str[5] = {0, 1, 2, 3, 4};
  	std::cout << "\tint_str  " << std::endl;
	iter (int_str, 5, print_func<int>);
	std::cout << std::endl;
	iter (int_str, 5, add<int>);
	std::cout << "int_str after iter(add) is called :" << std::endl;
	iter (int_str, 5, print_func<int>);
	std::cout << std::endl << std::endl;
	
  		//  Float array
	float 	flt_str[5] = {0.5f, 1.23f, 2.123f, 3.11f, -4.1123f};
	std::cout << "\tflt_str  " << std::endl;
	iter (flt_str, 5, print_func<float>);
	std::cout << std::endl;
	iter (flt_str, 5, add<float>);
	std::cout << "flt_str after iter(add) is called :" << std::endl;
	iter (flt_str, 5, print_func<float>);
	std::cout << std::endl << std::endl;

  		//  Struct array
	Astruct struct_str[5];
	for (int i = 0; i < 5; i++)
	{
		struct_str[i].value = -1;
		struct_str[i].structIdx = -1;
	}
	std::cout << "\tstruct_str  " << std::endl;
	iter (struct_str, 5, print_struct);
	std::cout << std::endl;
	iter(struct_str, 5, set_struct_value);
	std::cout << "struct_str after iter(set_struct_values) is called" << std::endl;
	iter(struct_str, 5, print_struct);
  return 0;
}
