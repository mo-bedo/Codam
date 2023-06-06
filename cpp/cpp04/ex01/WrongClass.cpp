#include "WrongClass.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal (WrongAnimal const &obj) {
	this->type = "WrongAnimal";
	*this = obj;
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator= (WrongAnimal const& obj) {
	this->type = "WrongAnimal";
	this->type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal () {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Hallo! I'm a WrongAnimal." << std::endl;
}

std::string	WrongAnimal::getType() const {
	return type;
}

WrongCat::WrongCat() {
	this->type = "WrongCat";
	this->_Brain = new Brain();
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat (const WrongCat &obj) : WrongAnimal(obj) {
	this->type = "WrongCat";
	this->_Brain = obj._Brain;
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator= (WrongCat const& obj) {
	this->type = "WrongCat";
	this->type = obj.type;
	this->_Brain = obj._Brain;
	return *this;
}

WrongCat::~WrongCat () {
	delete this->_Brain;
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "BarkBark, I'm a WrongCat." << std::endl;
}

std::string	WrongCat::get_idea(int index) const {
	return (this->_Brain->get_idea(index));
}

void		WrongCat::set_idea(std::string idea, int index) {
	this->_Brain->set_idea(idea, index);
}
