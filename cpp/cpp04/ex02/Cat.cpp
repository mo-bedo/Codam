#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() {
	this->_Brain = new Brain();
	this->type = "Cat";
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat (const Cat &obj) : Animal(obj) {
	*this = obj;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator= (Cat const& obj) {
	this->type = obj.type;
	this->_Brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_Brain->set_idea(obj._Brain->get_idea(i), i);
	return *this;
}

Cat::~Cat () {
	delete this->_Brain;
	std::cout << "Cat destructor called." << std::endl;
}

void		Cat::makeSound() const {
	std::cout << "Purpur, I'm a Cat." << std::endl;
}

std::string	Cat::get_idea(int index) const {
	return (this->_Brain->get_idea(index));
}

void		Cat::set_idea(std::string idea, int index) {
	this->_Brain->set_idea(idea, index);
}
