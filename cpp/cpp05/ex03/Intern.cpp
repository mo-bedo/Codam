#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

Intern::Intern ()
{
	if (INTERN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor Intern called." << std::endl;
}

Intern::Intern (const Intern &obj)
{
	*this = obj;
	if (INTERN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor Intern called." << std::endl;
}

Intern& Intern::operator= (const Intern &obj)
{
	(void) obj;
	if (INTERN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator Intern called." << std::endl;
	return *this;
}

Intern::~Intern ()
{
	if (INTERN_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Deconstructor Intern called." << std::endl;
}

AForm*	Intern::makeForm (std::string name, std::string target)
{
	std::string type_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*form_to_make = nullptr;
	int 		i = 0;

	while (i < 3)
	{
		if (type_name[i] == name)
			break ;
		i++;
	}
	switch (i)
	{
		case 0 :
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			form_to_make = new ShrubberyCreationForm(target);
			break;
		case 1 :
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			form_to_make = new RobotomyRequestForm(target);
			break;
		case 2 :
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			form_to_make = new PresidentialPardonForm(target);
			break;
		case 3 :
			std::cout << name << " not created (do not use return value). ";
			throw Intern::UnknownFormException();
	}
	return form_to_make;
}

const char* Intern::UnknownFormException::what() const throw ()
{
	return "Unknown form name.";
}
