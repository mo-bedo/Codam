#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap noName;
	noName.attack("something");
	FragTrap Henk ("Henk");
	Henk.attack("something");
	FragTrap Henk1 (Henk);
	Henk1.attack("something");
	FragTrap Arie("Arie");


	noName = Arie;

	std::cout << std::endl;

	for (int i = 0; i < 101 ; i++)
		noName.attack("a goblin");

	std::cout << std::endl;


	for (int i = 0; i < 5; i++)
	{
		Arie.attack("himself");
		Arie.takeDamage(20);
	}
	Arie.attack("something");

	std::cout << std::endl;

	Henk.highFivesGuys();
	Arie.highFivesGuys();

	std::cout << std::endl;

	ClapTrap* frag = new FragTrap("frag");
	frag->attack("something");
	delete frag;
	ClapTrap* scav = new ScavTrap("scav");
	scav->attack("something");
	delete scav;

	std::cout << std::endl;

	return 0;
}
