#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

AForm::AForm () : _name("default"), _signed(false), _req_sign_grade(AForm::_highest_grade), _req_exec_grade(AForm::_highest_grade)
{
	reviewAForm();
	if (AFORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Default constructor AForm called." << std::endl;
}

AForm::AForm (const std::string & name, int sign_grade, int exec_grade) :
		_name(name), _signed(false), _req_sign_grade(sign_grade), _req_exec_grade(exec_grade)
{
	reviewAForm();
	if (AFORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Named constructor AForm called." << std::endl;
}

AForm::AForm (const AForm &obj) : _name(obj.getName()), _signed(false), _req_sign_grade(obj.getReqSignGrade()),
								_req_exec_grade(obj.getReqExecGrade())
{
	reviewAForm();
	if (AFORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Copy constructor AForm called." << std::endl;
}

AForm& AForm::operator= (const AForm &obj)
{
	this->_signed = obj._signed;
	reviewAForm();
	if (AFORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Copy assignment operator AForm called. Constant values are assigned default values." << std::endl;
	return *this;
}

AForm::~AForm ()
{
	if (AFORM_PRINT_CONSTRUCT_MSG)
		std::cout << "Deconstructor AForm called." << std::endl;
}

void				AForm::reviewAForm() const
{
	if (this->getReqSignGrade() < AForm::_highest_grade || this->getReqExecGrade() < AForm::_highest_grade)
		throw AForm::GradeTooHighException();
	else if (this->getReqSignGrade() > AForm::_lowest_grade || this->getReqExecGrade() > AForm::_lowest_grade)
		throw AForm::GradeTooLowException();
}

const std::string& 	AForm::getName() const
{
	return this->_name;
}

bool 				AForm::getSignedStatus() const
{
	return this->_signed;
}

int	 				AForm::getReqSignGrade() const
{
	return this->_req_sign_grade;
}

int		 			AForm::getReqExecGrade() const
{
	return this->_req_exec_grade;
}

bool				AForm::beSigned(Bureaucrat const &signee)
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
		throw AForm::GradeTooLowException();
	}	
}

void				AForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSignedStatus())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getReqExecGrade())
		throw AForm::ExecutorGradeTooLowException();
	this->handleFormExecution();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high for Form";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low for Form";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return " cannot execute. Form is not signed";
}

const char *AForm::ExecutorGradeTooLowException::what() const throw()
{
	return " cannot execute. Executor grade is too low";
}

std::ostream& operator<< (std::ostream& out, AForm const & obj)
{
	out << "Form name: " << obj.getName() << ", req. execution grade: " << obj.getReqExecGrade()
		<< ", req. sign grade: " << obj.getReqSignGrade();
	if (obj.getSignedStatus())
		out << ", Form is signed.";
	else
		out << ", Form is not signed.";
	return out;
}