#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm () :
	AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	if (ROBOTOMYREQUESTFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor RobotomyRequestForm called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (const std::string & target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (ROBOTOMYREQUESTFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Named constructor RobotomyRequestForm called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &obj) :
		AForm("RobotomyRequestForm", 72, 45), _target(obj.getTarget())
{
	if (ROBOTOMYREQUESTFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor RobotomyRequestForm called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &obj)
{
	(void) obj;
	std::cout << "All class values are constant. Don't use copy assignment operator." << std::endl;
	if (ROBOTOMYREQUESTFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator RobotomyRequestForm called." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm ()
{
	if (ROBOTOMYREQUESTFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Destructor RobotomyRequestForm called." << std::endl;
}

const std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void 				RobotomyRequestForm::handleFormExecution() const
{
	std::cout << "* drilling noises *" << "\tExecution of " << this->getTarget();
	if (rand() % 2)
		std::cout << "'s Robotomy: succes." << std::endl;
	else
		std::cout << "'s Robotomy: failed." << std::endl;
}
