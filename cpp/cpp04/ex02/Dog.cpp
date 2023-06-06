#include "Brain.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() {
	this->_Brain = new Brain();
	this->type = "Dog";
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog (Dog const &obj) : Animal (obj) {
	*this = obj;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator= (Dog const& obj) {
	this->type = obj.type;
	this->_Brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_Brain->set_idea(obj._Brain->get_idea(i), i);
	return *this;
}

Dog::~Dog () {
	delete this->_Brain;
	std::cout << "Dog destructor called." << std::endl;
}

void		Dog::makeSound() const {
	std::cout << "Woefwoef, I'm a Dog." << std::endl;
}

std::string	Dog::get_idea(int index) const {
	return (this->_Brain->get_idea(index));
}

void		Dog::set_idea(std::string idea, int index) {
	this->_Brain->set_idea(idea, index);
}
