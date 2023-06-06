#ifndef FORM_HHP
# define FORM_HHP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

#define FORM_PRINT_CONSTRUCT_MSG false

class Bureaucrat;

class Form
{
private :
	const static int	_highest_grade = 1;
	const static int 	_lowest_grade = 150;

	const std::string	_name;
	bool 				_signed;
	const int			_req_sign_grade;
	const int 			_req_exec_grade;

	void 	reviewForm() const;

public :
	Form ();
	Form (const std::string &, int, int);
	Form (const Form &);
	Form &operator= (const Form &);
	~Form ();

	const std::string& 	getName() const;
	bool 				getSignedStatus() const;
	int 				getReqSignGrade() const;
	int	 				getReqExecGrade() const;
	bool 				beSigned(Bureaucrat const &);

	class GradeTooHighException : public std::exception
	{
	public :
		virtual const char* what () const throw ();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char*	what () const throw ();
	};

};

std::ostream& operator<< (std::ostream& out, Form const & obj);

#endif //		FORM_HHP
