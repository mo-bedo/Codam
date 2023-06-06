#include "Zombie.hpp"
#include <iostream>

int main()
{
	randomChump("Random Zombie");
	randomChump("Random Zombie#1");
	randomChump("Random Zombie#2");

	Zombie* dirk = newZombie("Dirk");
	Zombie* dirk1 = newZombie("Dirk#1");
	Zombie* dirk2 = newZombie("Dirk#2");

	std::cout << std::endl;

	dirk->announce();
	dirk1->announce();
	dirk2->announce();

	delete dirk;
	delete dirk1;
	delete dirk2;

	return 0;
}
