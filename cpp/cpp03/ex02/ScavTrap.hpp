#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public :
	ScavTrap();
	ScavTrap(std::string const &);
	ScavTrap(ScavTrap const &);
	ScavTrap& operator=(ScavTrap const &);
	~ScavTrap();

	void	attack(const std::string& target);
	void	GuardGate();
};

#endif 		// SCAVTRAP_HPP
