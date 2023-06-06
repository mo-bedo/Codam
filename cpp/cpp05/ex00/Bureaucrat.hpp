#ifndef BUREAUCRAT_HHP
#define BUREAUCRAT_HHP

#include <string>
#include <exception>

#define PRINT_CONSTRUCTOR_MSG false

class Bureaucrat
{
	private :
		const std::string	_name;
		int 				_grade;

		const static int	_highest_grade = 1;
		const static int	_lowest_grade = 150;

		void	reviewGrade();

	public :

		Bureaucrat ();
		Bureaucrat (const std::string&, int);
		Bureaucrat (const Bureaucrat &);
		Bureaucrat& operator= (const Bureaucrat &);
		~Bureaucrat ();

		std::string	getName () const;
		int 		getGrade () const;
		
		void 		decrementGrade(int);
		void		incrementGrade(int);

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
