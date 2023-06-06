#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() {
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->_Name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "ScavTrap constructor called. My name is " << this->_Name
			  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap() {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "ScavTrap copy constructor called. My name is "
			  << this->_Name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "ScavTrap copy assignment operator called. My name is "
			  << this->_Name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap ";
	if (this->_Name.size() != 0)
		std::cout << this->_Name << " is no more. ";
	 std::cout << "ScavTrap Deconstructor is called." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap ";
	if (this->_HitPoints <= 0)
	{
		if (this->_Name.size() != 0)
			std::cout << this->_Name << " ";
		std::cout << "has 0 or negative HP so he cannot attack." << std::endl;
		return;
	}
	else if (this->_EnergyPoints <= 0)
	{
		if (this->_Name.size() != 0)
			std::cout << this->_Name << " ";
		std::cout << this->_Name << "is too tired to attack." << std::endl;
		return;
	}
	this->_EnergyPoints--;
	if (this->_Name.size() != 0)
		std::cout << this->_Name << " ";
	std::cout << "attacks " << target << " for " << this->_AttackDamage <<
			  " points of damage! Leaving " << this->_EnergyPoints <<
			  " points of Energy." << std::endl;
}

void 	ScavTrap::GuardGate() {
	std::cout << "ScavTrap ";
	if (this->_Name.size() != 0)
		std::cout << this->_Name << " ";
	std::cout << "is now in Gate keeper mode."
			  << std::endl;
}
