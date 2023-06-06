#ifndef BUREAUCRAT_HHP
#define BUREAUCRAT_HHP

#include "Form.hpp"
#include <string>
#include <exception>

#define BUREAUCRAT_PRINT_CONSTRUCTOR_MSG false

class Form;

class Bureaucrat
{
	private :
		const std::string	_name;
		int 				_grade;

		const static int	_highest_grade = 1;
		const static int	_lowest_grade = 150;

		void	reviewGrade() const;

	public :

		Bureaucrat ();
		Bureaucrat (const std::string&, int);
		Bureaucrat (const Bureaucrat &);
		Bureaucrat& operator= (const Bureaucrat &);
		~Bureaucrat ();

		std::string	getName () const;
		int 		getGrade () const;

		void		incrementGrade(int);
		void 		decrementGrade(int);
		void		signForm(Form &) const;

		class GradeTooHighException : public std::exception
		{
		public :
			virtual const char* what () const throw ();
		};

		class GradeTooLowException : public std::exception
		{
		public :
			virtual const char* what () const throw ();
		};
};

std::ostream& operator << (std::ostream& out, Bureaucrat const & obj);

#endif //		BUREAUCRAT_HHP
