#include "Brain.hpp"
#include <iostream>

Brain::Brain () {
	std::cout << "Default Brain Constructor called." << std::endl;
}

Brain::Brain (const Brain& obj) {
	*this = obj;
	std::cout << "Brain Copy Constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain &obj) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

std::string	Brain::get_idea(int index) const {
	return this->ideas[index];
}

void		Brain::set_idea(std::string idea, int index) {
	this->ideas[index] = idea;
}
