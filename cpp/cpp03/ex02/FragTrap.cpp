#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string const & name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor called. My name is " <<
			  this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap() {
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "FragTrap copy constructor called. My name is "
			  << this->_name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj) {
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "FragTrap copy assignment operator called. My name is "
			  << this->_name << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is being deconstructed. " << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap ";
	if (!this->_name.empty())
		std::cout << this->_name << " ";
	std::cout << "requests positive high fives! " << std::endl;
}
