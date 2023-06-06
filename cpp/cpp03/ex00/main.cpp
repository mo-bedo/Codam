#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap Henk;
    ClapTrap Dirk("Dirk");
	ClapTrap Piet("Piet");
	ClapTrap Frank(Piet);
    Henk = Dirk;

    std::cout << std::endl;
    Dirk.attack("Frenk");
    Dirk.takeDamage(8);
    Dirk.takeDamage(5);
    Dirk.attack("something");
	Dirk.beRepaired(2);

    std::cout << std::endl;
    Henk.takeDamage(4);
    Henk.beRepaired(5);

	std::cout << std::endl;
	Dirk = Piet;
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
	Dirk.attack("a wolf");
    Dirk.beRepaired(33);

	std::cout << std::endl;

	return 0;
}
