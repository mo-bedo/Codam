#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Claptrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap (std::string const & name) :
        _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Name constructor called. New Claptrap: " << this->_name << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &obj) : _name(obj._name),
		_hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints),
		_attackDamage(obj._attackDamage)  {
    std::cout << "Copy constructor called. New Claptrap: " << this->_name << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &obj) {
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	if (!this->_name.empty())
		std::cout << this->_name << " is no more. ";
	std::cout << "Destructor called." << std::endl;
}

void    ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack since he has no HitPoints left!" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack since he has no Energy left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->_name << " takes " << amount
			  << " points of damage! His HP is now ";
	this->_hitPoints -= amount;
	std::cout << this->_hitPoints << "." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " cannot repair since he has no HitPoints left!" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " cannot repair since he has no Energy left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << this->_name << " repairs himself for the amount of "
			  << amount << ". Leaving him with " << this->_hitPoints << " HP." << std::endl;
}
