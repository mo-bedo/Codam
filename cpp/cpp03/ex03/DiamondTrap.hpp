#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private :
	std::string	_name;

public :
	DiamondTrap();
	DiamondTrap(const std::string &);
 	DiamondTrap(const DiamondTrap &);
	DiamondTrap& operator=(const DiamondTrap &);
	~DiamondTrap();

	void	whoAmI();
};

#endif		// DIAMONDTRAP_HPP
