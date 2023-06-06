#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Form::Form () : _name("default"), _signed(false), _req_sign_grade(Form::_highest_grade), _req_exec_grade(Form::_highest_grade)
{
	reviewForm();
	if (FORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Default constructor Form called." << std::endl;
}

Form::Form (const std::string & name, int sign_grade, int exec_grade) :
		_name(name), _signed(false), _req_sign_grade(sign_grade), _req_exec_grade(exec_grade)
{
	reviewForm();
	if (FORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Named constructor Form called." << std::endl;
}

Form::Form (const Form &obj) : _name(obj.getName()), _signed(false), _req_sign_grade(obj.getReqSignGrade()),
								_req_exec_grade(obj.getReqExecGrade())
{
	reviewForm();
	if (FORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Copy constructor Form called." << std::endl;
}

Form& Form::operator= (const Form &obj)
{
	this->_signed = obj.getSignedStatus();
	reviewForm();
	if (FORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Copy assignment operator Form called. Constant values are assigned default values." << std::endl;
	return *this;
}

Form::~Form ()
{
	if (FORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Deconstructor Form called." << std::endl;
}

void				Form::reviewForm() const
{
	if (this->getReqSignGrade() < Form::_highest_grade || this->getReqExecGrade() < Form::_highest_grade)
		throw Form::GradeTooHighException();
	else if (this->getReqSignGrade() > Form::_lowest_grade || this->getReqExecGrade() > Form::_lowest_grade)
		throw Form::GradeTooLowException();
}

const std::string& 	Form::getName() const
{
	return this->_name;
}

bool 				Form::getSignedStatus() const
{
	return this->_signed;
}

int 				Form::getReqSignGrade() const
{
	return this->_req_sign_grade;
}

int 				Form::getReqExecGrade() const
{
	return this->_req_exec_grade;
}

bool				Form::beSigned(Bureaucrat const &signee)
{
	if (this->_signed)
		return false;
	if (signee.getGrade() <= this->getReqSignGrade())
	{
		this->_signed = true;
		return true;
	}
	else
	{
		std::cout << signee.getName() << " couldn't sign " << this->getName() << " because ";
		throw Form::GradeTooLowException();
	}	
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high for form";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low for form";
}

std::ostream& operator<< (std::ostream& out, Form const & obj)
{
	out << "Form name: " << obj.getName() << ", required execution grade: " << obj.getReqExecGrade()
		<< ", required sign grade: " << obj.getReqSignGrade();
	if (obj.getSignedStatus())
		out << ", form is signed.";
	else
		out << ", form is not signed.";
	return out;
}
