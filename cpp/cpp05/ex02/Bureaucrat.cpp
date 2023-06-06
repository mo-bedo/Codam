#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat () : _name("DefaultDrone"), _grade(Bureaucrat::_lowest_grade)
{
	if (BUREAUCRAT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Named constructor Bureaucrat called." << std::endl;
	this->reviewGrade();
}

Bureaucrat::Bureaucrat (const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (BUREAUCRAT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Named constructor Bureaucrat called." << std::endl;
	this->reviewGrade();
}

Bureaucrat::Bureaucrat (const Bureaucrat &obj) : _name(obj.getName()) 
{
	*this = obj;
	if (BUREAUCRAT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy constructor Bureaucrat called." << std::endl;
	this->reviewGrade();
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &obj)
{
	this->_grade = obj._grade;
	if (BUREAUCRAT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Copy assignment operator Bureaucrat called. Name is not copied since it's a constant." << std::endl;
	this->reviewGrade();
	return *this;
}

Bureaucrat::~Bureaucrat ()
{
	if (BUREAUCRAT_PRINT_CONSTRUCTOR_MSG)
		std::cout << "Deconstructor Bureaucrat called." << std::endl;
}

std::string Bureaucrat::getName () const
{
	return this->_name;
}

int 		Bureaucrat::getGrade () const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade (int incr)
{
	if (incr > 150 || incr < -150)
	{
		std::cout << "Cannot increment grade by more (or less) then (-)150" << std::endl;
		return ;
	}
	std::cout << "Trying to increment the grade of " << *this << ", by " << incr << std::endl;
	if ((this->getGrade() - incr) < Bureaucrat::_highest_grade)
		throw Bureaucrat::GradeTooHighException();
	if ((this->getGrade() - incr) > Bureaucrat::_lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade -= incr;
	std::cout << "New grade: " << *this << std::endl;
}

void 		Bureaucrat::decrementGrade (int decr)
{
	if (decr > 150 || decr < -150)
	{
		std::cout << "Cannot increment grade by more or less then (-)150" << std::endl;
		return ;
	}
	std::cout << "Trying to decrement the grade of " << *this << ", by " << decr << std::endl;
	if ((this->getGrade() + decr) > Bureaucrat::_lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	if ((this->getGrade() + decr) < Bureaucrat::_highest_grade)
		throw Bureaucrat::GradeTooHighException();	
	this->_grade += decr;
	std::cout << "New grade: " << *this << std::endl;
}

void 		Bureaucrat::executeForm(const AForm & form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << e.what() << std::endl;
		return;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

void 		Bureaucrat::signForm (AForm& form) const
{
	if (form.beSigned(*this))
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		return;
	}
	std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
	std::cout << "the form was already signed." << std::endl;
}

void		Bureaucrat::reviewGrade () const
{
	if (this->getGrade() < Bureaucrat::_highest_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->getGrade() > Bureaucrat::_lowest_grade)
		throw Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}


std::ostream& operator << (std::ostream& out, Bureaucrat const & obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}
