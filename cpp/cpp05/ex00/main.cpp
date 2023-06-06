#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main ()
{
	std::cout << std::endl << "\t\tShowing orthodox canonical form" << std::endl << std::endl;

	Bureaucrat 	defaultdrone;
	std::cout << defaultdrone << std::endl << std::endl;

	Bureaucrat 	named("Henk", 1);
	std::cout <<  named << std::endl << std::endl;

	Bureaucrat 	copy(named);
	std::cout << copy << std::endl << std::endl;

	Bureaucrat	copy_assignment;
	copy_assignment = copy;
	std::cout << copy_assignment << std::endl;

	std::cout << std::endl << "\t\tCreating two bureaucrats with valid grade values. Then we will "
				<< "increment and decrement their grades untill one is invalid"
				<< std::endl << std::endl;;

	Bureaucrat dirk("Dirk", 150);
	Bureaucrat frank("Frank", 150);

	std::cout << dirk << std::endl << frank << std::endl;
	try
	{
		dirk.incrementGrade(1);
		frank.incrementGrade(100);
		dirk.decrementGrade(2);
		std::cout << "\t\tThis code will not run" << std::endl;;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Dirk will still have his old grade. " << dirk << std::endl;


	std::cout << std::endl << "\t\tNow two new Bureaucrats with invalid grade values from the start"
		 		<< std::endl << std::endl;

	try
	{
		Bureaucrat grade_too_low("Nope", 1000);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat grade_too_high = Bureaucrat ("NopeAgain", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
