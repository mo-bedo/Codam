#include "AMateria.hpp"
#include "Ice.hpp"
#include <iostream>

Ice::Ice () : AMateria("ice") {
	std::cout << "Ice Default Constructor called." << std::endl;
	this->_type = "ice";
}

Ice::Ice (const Ice &obj) : AMateria("ice") {
	std::cout << "Ice Default Constructor called." << std::endl;
	this->_type = obj.getType();
}

Ice& Ice::operator= (const Ice &obj) {
	this->_type = obj.getType();
	return *this;
}

Ice::~Ice () {
	std::cout << "Ice destructor called." << std::endl;
}


AMateria* Ice::clone() const {
	AMateria* newIce = new Ice();
	return newIce;
}

void Ice::use (ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}