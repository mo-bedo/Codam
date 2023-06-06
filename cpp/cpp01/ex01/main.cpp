#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie*	horde;
	int 	hordeAmount = 6;

	std::cout << "At the local cemetery an evil necromancer is performing some weird ritual." << std::endl;
	horde = zombieHorde(hordeAmount, "Harry");
	for (int i = 0; i < hordeAmount; i++)
		horde[i].announce();
	std::cout << "But the zombies are lazy." << std::endl;
	delete[] horde;

	std::cout << "So the necromancer tries again..." << std::endl;
	hordeAmount = 12;
	horde = zombieHorde(hordeAmount, "Harry2.0");
	for (int i = 0; i < hordeAmount; i++)
		horde[i].announce();
	std::cout << "But the zombies are sleepy." << std::endl;
	delete[] horde;

	std::cout << "And again..." << std::endl;
	hordeAmount = 5;
	horde = zombieHorde(hordeAmount, "Harry2.1");
	for (int i = 0; i < hordeAmount; i++)
		horde[i].announce();
	std::cout << "But the zombies don't like the 'outside'." << std::endl;
	delete[] horde;

	std::cout << "And again..." << std::endl;
	hordeAmount = -50;
	horde = zombieHorde(hordeAmount, "Harry2.2");

	std::cout << "Untill he gets fed up with the zombies and goes home." << std::endl;
	return 0;
}
