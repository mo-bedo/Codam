#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal (Animal const &obj) {
	*this = obj;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator= (Animal const& obj) {
	this->type = obj.type;
	return *this;
}

Animal::~Animal () {
	std::cout << "Animal destructor called." << std::endl;
}

void			Animal::makeSound() const {
	std::cout << "Kawkaw, I'm an Animal." << std::endl;
}

std::string		Animal::getType() const {
	return type;
}
