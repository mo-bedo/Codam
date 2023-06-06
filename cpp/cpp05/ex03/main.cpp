#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>
#include <stdlib.h>

int main ()
{
	Intern	someRandomIntern;
	AForm*	rrf;
	AForm*	scf;
	AForm*	ppp;
	AForm*	wrongFormName;

	srand (time(NULL));
	try 
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "xmas_tree");
		ppp = someRandomIntern.makeForm("presidential pardon", "criminal");
		wrongFormName = someRandomIntern.makeForm("rabatamy request", "something");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat bert("bert", 1);

	bert.signForm(*rrf);
	bert.executeForm(*rrf);

	bert.signForm(*scf);
	bert.executeForm(*scf);

	bert.signForm(*ppp);
	bert.executeForm(*ppp);

	delete rrf;
	delete ppp;
	delete scf;
	return (0);
}
