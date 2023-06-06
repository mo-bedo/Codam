#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->_Name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap constructor called. My name is " <<
			  this->_Name << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap() {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "FragTrap copy constructor called. My name is "
			  << this->_Name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj) {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "FragTrap copy assignment operator called. My name is "
			  << this->_Name << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_Name << " is being deconstructed. " << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_Name << " requests positive high fives! " << std::endl;
}
