#ifndef ROBOTOMYREQUESTFORM_HHP
# define ROBOTOMYREQUESTFORM_HHP

# define ROBOTOMYREQUESTFORM_PRINT_CONSTRUCTOR_MSG	false

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private :
	const std::string	_target;
public :
	RobotomyRequestForm ();
	RobotomyRequestForm (const std::string &);
	RobotomyRequestForm (const RobotomyRequestForm &);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &);
	~RobotomyRequestForm ();

	const std::string 	getTarget() const;
	void				handleFormExecution () const;

};

#endif //		ROBOTOMYREQUESTFORM_HHP
