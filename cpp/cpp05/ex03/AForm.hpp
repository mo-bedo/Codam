#ifndef AFORM_HHP
# define AFORM_HHP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

#define AFORM_PRINT_CONSTRUCT_MSG false

class Bureaucrat;

class AForm
{
private :
	const static int	_highest_grade = 1;
	const static int 	_lowest_grade = 150;

	const std::string	_name;
	bool 				_signed;
	const int			_req_sign_grade;
	const int 			_req_exec_grade;
	void 	reviewAForm() const;

public :
	AForm ();
	AForm (const std::string &, int, int);
	AForm (const AForm &);
	AForm &operator= (const AForm &);
	virtual ~AForm ();

	const std::string& 	getName () const;
	bool 				getSignedStatus () const;
	int 				getReqSignGrade () const;
	int		 			getReqExecGrade () const;
	bool				beSigned (Bureaucrat const &);
	void				execute (Bureaucrat const &) const;
	virtual void		handleFormExecution () const = 0;

	class GradeTooHighException : public std::exception
	{
	public :
		virtual const char* what () const throw ();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char*	what () const throw ();
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char*	what () const throw ();
	};

	class ExecutorGradeTooLowException : public std::exception
	{
		virtual const char*	what () const throw ();
	};

};

std::ostream& operator<< (std::ostream& out, AForm const & obj);

#endif //		AFORM_HHP
