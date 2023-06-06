#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.hpp"

class 	PhoneBook {
public :
	PhoneBook();
	~PhoneBook();
	Contact		contacts[8];
	void		search() const;
};

#endif	// PHONEBOOK_CLASS_HPP
