#include "Zombie.hpp"
#include <string>

Zombie*	newZombie (std::string name)
{
	Zombie* createZombie = new Zombie;

	createZombie->setName (name);
	return createZombie;
}
