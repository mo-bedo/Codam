#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap Henk;
	ScavTrap Arie("Arie");
	ScavTrap Copy("Frenk");
	ScavTrap Frenk;
	ScavTrap Frenk1(Copy);
	Frenk = Copy;

	std::cout << std::endl;

	ClapTrap *show_virtual = new ScavTrap("test");
	show_virtual->attack("something");
	delete show_virtual;

	std::cout << std::endl;

	for (int i = 0; i < 51 ; i++)
		Frenk.attack("a goblin");
	Frenk.beRepaired(1);

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		Arie.attack("himself");
		Arie.takeDamage(20);
	}
	Arie.attack("something");
	Arie.beRepaired(12);

	std::cout << std::endl;

	Henk.GuardGate();
	Arie.GuardGate();

	std::cout << std::endl;

	return 0;
}
