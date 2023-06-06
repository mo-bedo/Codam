#include "FragTrap.hpp"
#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond ("Diamond");
	diamond.whoAmI();
	diamond.showStats();
	diamond.attack("attacks_as_scav");

	std::cout << std::endl;

	FragTrap frag ("Frag");
	frag.showStats();
	frag.attack("attaks_as_clap");

	std::cout << std::endl;

	ScavTrap scav ("Scav");
	scav.showStats();
	scav.attack ("attacks_as_scav");

	std::cout << std::endl;

	ClapTrap* clapPointer = new DiamondTrap("clapPointer");
	FragTrap* fragPointer = new DiamondTrap("fragPointer");
	ScavTrap* scavPointer = new DiamondTrap("scavPointer");
	clapPointer->showStats();
	fragPointer->showStats();
	scavPointer->showStats();
	clapPointer->attack("something");
	fragPointer->attack("something");		// since pointer points to diamondtrap object scavtrap attack is still called
	scavPointer->attack("something");

	std::cout << std::endl;

	delete clapPointer;
	delete fragPointer;
	delete scavPointer;

	return 0;
}
