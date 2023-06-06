#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public :
	FragTrap();
	FragTrap(std::string const &);
	FragTrap(FragTrap const &);
	FragTrap& operator=(FragTrap const &);
	~FragTrap();

	void 	highFivesGuys(void);
};


#endif 		// FRAGTRAP_HPP
