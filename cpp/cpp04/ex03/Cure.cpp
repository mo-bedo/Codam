#include "AMateria.hpp"
#include "Cure.hpp"
#include <iostream>

Cure::Cure () : AMateria("cure") {
	std::cout << "Cure Default Constructor called." << std::endl;
	this->_type = "cure";
}

Cure::Cure (const Cure &obj) : AMateria("cure") {
	std::cout << "Cure Default Constructor called." << std::endl;
	this->_type = obj.getType();
}

Cure& Cure::operator= (const Cure &obj) {
	this->_type = obj.getType();
	return *this;
}

Cure::~Cure () {
	std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const {
	AMateria* newCure = new Cure();
	return newCure;
}

void Cure::use (ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
