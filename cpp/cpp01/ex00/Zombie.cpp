#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie ()
{
}

Zombie::~Zombie ()
{
	std::cout << this->name << " returns to the grave." << std::endl;
}

void	Zombie::announce ()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string inputname)
{
	this->name = inputname;
}
