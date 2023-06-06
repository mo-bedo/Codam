#ifndef PRESIDENTIALPARDONFORM_HHP
# define PRESIDENTIALPARDONFORM_HHP

# define PRESIDENTIALPARDONFORM_PRINT_CONSTRUCTOR_MSG	false

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private :
	const std::string	_target;
public :
	PresidentialPardonForm ();
	PresidentialPardonForm (const std::string &);
	PresidentialPardonForm (const PresidentialPardonForm &);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &);
	~PresidentialPardonForm ();

	std::string		getTarget() const;
	void			handleFormExecution () const;
};

#endif //		PRESIDENTIALPARDONFORM_HHP
