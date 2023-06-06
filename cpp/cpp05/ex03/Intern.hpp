#ifndef INTERN_HHP
# define INTERN_HHP

# define INTERN_PRINT_CONSTRUCTOR_MSG	false

#include <string>
#include "AForm.hpp"

class Intern
{
public :
	Intern ();
	Intern (const Intern &);
	Intern &operator= (const Intern &);
	~Intern ();

	AForm*	makeForm(std::string, std::string);

	class UnknownFormException : public std::exception 
	{
	public :
		virtual const char* what() const throw ();
	};
};

#endif //		INTERN_HHP
