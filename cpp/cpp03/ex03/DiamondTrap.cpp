#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(){
	ClapTrap::_Name += "_clap_name";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) {
	this->_name = name;
	ClapTrap::_Name = name + "_clap_name";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(), FragTrap(), ScavTrap() {
	*this = obj;
	std::cout << "DiamondTrap Copy Constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	this->_name = obj._name;
	ClapTrap::_Name = this->_name + "_clap_name";
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "DiamondTrap Copy Assignment operator called." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->_name << " DiamondTrap deconstructor called." << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "My name: " << this->_name << std::endl;
	std::cout << "My ClapTrap name: " << ClapTrap::_Name << std::endl;
}
