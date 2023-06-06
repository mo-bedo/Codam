#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm () :
	AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	if (PRESIDENTIALPARDONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor PresidentialPardonForm called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (const std::string & target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (PRESIDENTIALPARDONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Named constructor PresidentialPardonForm called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &obj) :
	AForm("PresidentialPardonForm", 25, 5), _target(obj.getTarget())
{
	if (PRESIDENTIALPARDONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor PresidentialPardonForm called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &obj)
{
	(void) obj;
	std::cout << "All class values are constant. Don't use copy assignment operator." << std::endl;
	if (PRESIDENTIALPARDONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator PresidentialPardonForm called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm ()
{
	if (PRESIDENTIALPARDONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Deconstructor PresidentialPardonForm called." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void 		PresidentialPardonForm::handleFormExecution() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
