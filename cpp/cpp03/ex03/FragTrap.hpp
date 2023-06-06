#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap :  virtual public ClapTrap {
public :
	FragTrap();
	FragTrap(std::string);
	FragTrap(FragTrap const &);
	FragTrap& operator=(FragTrap const &);
	~FragTrap();

	void highFivesGuys(void);
};


#endif 		// FRAGTRAP_HPP
