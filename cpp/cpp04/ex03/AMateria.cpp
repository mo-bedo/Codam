#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria (std::string const & type) {
	std::cout << "AMateria type Constructor called." << std::endl;
	this->_type = type;
}

AMateria::~AMateria ()
{
	std::cout << "AMateria destructor called." << std::endl;
}

std::string const & AMateria::getType () const {
	return this->_type;
}
