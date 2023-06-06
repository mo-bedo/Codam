#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>
#include <stdlib.h>

#define GREEN   "\e[32m"
#define BLUE    "\e[0;34m"
#define NORMAL  "\e[00m"

int main ()
{
	srand(time(NULL));

	Bureaucrat high_level("high_level", 1);
	Bureaucrat mid_level("mid_level", 46);
	Bureaucrat low_level("low_level", 150);

	AForm *shrub = new ShrubberyCreationForm("shrub");
	AForm *shrub1 = new ShrubberyCreationForm("shrub1");
	AForm *shrub2 = new ShrubberyCreationForm("shrub2");

	/*
			Sign Shrub forms:
	*/
	std::cout << GREEN << "\tSign Shrub forms: " << NORMAL << std::endl;
	try
	{
		high_level.signForm(*shrub);
		mid_level.signForm(*shrub1);
		low_level.signForm(*shrub2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BLUE << "\tExecute Shrub forms: " << NORMAL << std::endl;
	
	high_level.executeForm(*shrub);
	mid_level.executeForm(*shrub1);
	low_level.executeForm(*shrub2);

	high_level.signForm(*shrub2);
	low_level.executeForm(*shrub2);

	delete shrub1;
	delete shrub2;
	delete shrub;

	AForm *robotomize = new RobotomyRequestForm("Drone");
	AForm *robotomize1 = new RobotomyRequestForm("Drone1");
	AForm *robotomize2_not_signed = new RobotomyRequestForm("Drone2");

	/*
			Sign Robotomy forms

	*/
	std::cout << std::endl << GREEN << "\tSign Robotomy forms: " << NORMAL << std::endl;
	try
	{
		high_level.signForm(*robotomize);
		mid_level.signForm(*robotomize1);
		low_level.signForm(*robotomize2_not_signed);
		
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE << "\tExecute Robotomy forms: " << NORMAL << std::endl;
	high_level.executeForm(*robotomize);
	mid_level.executeForm(*robotomize1);
	mid_level.incrementGrade(1);
	mid_level.executeForm(*robotomize1);
	low_level.executeForm(*robotomize2_not_signed);

	for (int i = 0; i < 10; i++)
		high_level.executeForm(*robotomize);

	delete robotomize;
	delete robotomize1;
	delete robotomize2_not_signed;

	AForm* pardon = new PresidentialPardonForm("Subject");
	AForm* pardon1 = new PresidentialPardonForm("Subject1");
	AForm* pardon2 = new PresidentialPardonForm("Subject2");

	/*
			Sign Pardon forms:
	
	*/
	std::cout << std::endl << GREEN << "\tSign Pardon forms: " << NORMAL << std::endl;
	try
	{
		high_level.signForm(*pardon);
		mid_level.signForm(*pardon1);
		mid_level.incrementGrade(20);
		mid_level.signForm(*pardon1);
		low_level.signForm(*pardon2);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << BLUE << "\tExecute pardon forms: " << NORMAL << std::endl;
	high_level.executeForm(*pardon);
	mid_level.executeForm(*pardon1);
	low_level.executeForm(*pardon2);

	delete pardon;
	delete pardon1;
	delete pardon2;

	return (0);
}
