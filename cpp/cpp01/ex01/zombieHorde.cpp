#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Can't have a zero or negative horde." << std::endl;
		return nullptr;
	}
	Zombie* horde =	new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName (name);
	return horde;
}
