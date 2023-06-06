#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm () :
	AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	if (SHRUBBERYCREATIONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Default constructor ShrubberyCreationForm called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (const std::string & target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (SHRUBBERYCREATIONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Named constructor ShrubberyCreationForm called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &obj) :
	AForm("ShrubberyCreationForm", 145, 137), _target(obj.getTarget())
{
	if (SHRUBBERYCREATIONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor ShrubberyCreationForm called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &obj)
{
	(void) obj;
	std::cout << "All class values are constant. Don't use copy assignment operator." << std::endl;
	if (SHRUBBERYCREATIONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator ShrubberyCreationForm called." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm ()
{
	if (SHRUBBERYCREATIONFORM_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Destructor ShrubberyCreationForm called." << std::endl;
}

const std::string 	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void				ShrubberyCreationForm::handleFormExecution () const
{
	std::string		file_name = this->getTarget() + "_shrubbery";
	std::ofstream	shrub_file (file_name.c_str());


	shrub_file << "      *      " << std::endl;
	shrub_file << "     ***      " << std::endl;
	shrub_file << "    *****      " << std::endl;
	shrub_file << "      |          *      " << std::endl;
	shrub_file << "                ***  " << std::endl;
	shrub_file << "               *****  " << std::endl;
	shrub_file << "                ***  " << std::endl;
	shrub_file << "                 |  " << std::endl;
	shrub_file << "                 |  " << std::endl;
	shrub_file << "                                       " << std::endl;
	shrub_file << "        *                                  " << std::endl;
	shrub_file << "       ***                                 " << std::endl;
	shrub_file << "      *****                                 " << std::endl;
	shrub_file << "       ***                                   " << std::endl;
	shrub_file << "      *****                                    " << std::endl;
	shrub_file << "     *******                                     " << std::endl;
	shrub_file << "    *********                                     " << std::endl;
	shrub_file << "       ||                                      " << std::endl;
	shrub_file << "                                             " << std::endl;
}
