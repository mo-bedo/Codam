#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
    std::cout << "ClapTrap Default Constructor called. " << std::endl;
}

ClapTrap::ClapTrap (std::string name) {
	this->_Name = name;
	this->_HitPoints = 10;
	std::cout << "ClapTrap Constructor called. ";
	this->sayMyName();
}

ClapTrap::ClapTrap (ClapTrap const &obj) {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "ClapTrap Copy Constructor called. ";
	this->sayMyName();
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &obj) {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_AttackDamage = obj._AttackDamage;
	std::cout << "ClapTrap Copy assignment operator called. ";
	this->sayMyName();
	return *this;
}

ClapTrap::~ClapTrap() {
	if (this->_Name.size() != 0)
		std::cout << this->_Name << " is no more! ";
	std::cout << "ClapTrap Deconstructor called." << std::endl;
}

void    ClapTrap::attack(const std::string &target) {
    if (this->_HitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_Name << " cannot attack since he has no HitPoints left!" << std::endl;
        return ;
    }
    else if (this->_EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_Name << " cannot attack since he has no Energy left!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_Name << " attacks " << target
                << ", causing " << this->_AttackDamage
                << " points of damage! ";
    this->_EnergyPoints--;
    std::cout << "His attack used up 1 energypoint, leaving him with "
                << this->_EnergyPoints << " energy." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "Claptrap " << this->_Name << " takes " << amount
                << " points of damage! His HP is now ";
    this->_HitPoints -= amount;
    std::cout << this->_HitPoints << "." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    this->_HitPoints += amount;
	std::cout << "ClapTrap " << _Name << " is being repaired for the amount of "
				<< amount << ". Leaving him with " << _HitPoints << " HP." << std::endl;
}

void	ClapTrap::showStats() {
	if (this->_Name.size() != 0)
		std::cout << "I am " << this->_Name << ". ";
	std::cout << "My stats are: " << std::endl
			  << "HP:\t\t" << _HitPoints << std::endl << "Energy:\t\t" <<
			  this->_EnergyPoints << std::endl << "Attack damage:\t" <<
			  this->_AttackDamage << std::endl;
}

void	ClapTrap::sayMyName() {
	std::cout << "My name is " << this->_Name << "." << std::endl;
}