#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap named constructor called. My name is " << this->_name
			  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap() {
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "ScavTrap copy constructor called. My name is "
			  << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "ScavTrap copy assignment operator called. " << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	if (!this->_name.empty())
		std::cout << this->_name << " is no more. ";
	std::cout << "ScavTrap Deconstructor is called." << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap ";
	if (this->_hitPoints <= 0)
	{
		if (this->_name.size() != 0)
			std::cout << this->_name << " ";
		std::cout << "has 0 or negative HP so he cannot attack." << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		if (this->_name.size() != 0)
			std::cout << this->_name << " ";
		std::cout << "is too tired to attack." << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (this->_name.size() != 0)
		std::cout << this->_name << " ";
	std::cout << "attacks " << target << " for " << this->_attackDamage <<
			  " points of damage! Leaving " << this->_energyPoints <<
			  " points of Energy." << std::endl;
}

void 	ScavTrap::GuardGate() {
	std::cout << "ScavTrap ";
	if (this->_name.size() != 0)
		std::cout << this->_name << " ";
	std::cout << "is now in Gate keeper mode."
			  << std::endl;
}
