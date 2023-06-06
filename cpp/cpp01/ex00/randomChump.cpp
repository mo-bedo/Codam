#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name)
{
	Zombie throwaway;

	throwaway.setName (name);
	throwaway.announce ();
}
