#ifndef SHRUBBERYCREATIONFORM_HHP
# define SHRUBBERYCREATIONFORM_HHP

#include "AForm.hpp"
#include <string>

# define SHRUBBERYCREATIONFORM_PRINT_CONSTRUCTOR_MSG	false

class ShrubberyCreationForm : public AForm
{
private :
	const std::string	_target;
public :
	ShrubberyCreationForm ();
	ShrubberyCreationForm (const std::string &);
	ShrubberyCreationForm (const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &);
	~ShrubberyCreationForm ();

	const std::string 	getTarget() const;
	void				handleFormExecution () const;
	//	void				execute (Bureaucrat const & executor) const;

};

#endif //		SHRUBBERYCREATIONFORM_HHP
