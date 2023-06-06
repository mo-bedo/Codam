#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main ()
{
	Bureaucrat 	bert ("bert", 135);

	Form		form_125 ("form_125", 125, 125);

	std::cout << "Bureaucrat bert will try to sign our form_125. If he fails he will receive "
				"a promotion and then try again, untill he can sign the form" << std::endl;
	std::cout << form_125 << std::endl;
	while (!form_125.getSignedStatus())
	{
		bert.incrementGrade(2);
		try
		{
			bert.signForm(form_125);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << form_125 << std::endl;
	bert.signForm(form_125);
	std::cout << std::endl;

	try
	{
		Form		wrong_form("wrong_form", 13, 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form		wrong_form1("wrong_form1", 0, 35);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form		wrong_form2("wrong_form2", 0, 155);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat 	dirk("Dirk", 20);
	Form		form_1("form_1", 1, 1);
	try {
		std::cout << dirk << " will try to sign " << form_1 << std::endl;
		dirk.signForm(form_1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	dirk.incrementGrade(19);
	try
	{
		dirk.signForm(form_1);
		dirk.signForm(form_1);			
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return 0;
}