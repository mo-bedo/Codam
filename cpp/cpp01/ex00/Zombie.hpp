#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private :
	std::string	name;
public :
	Zombie ();
	~Zombie ();
	void 	setName (std::string inputname);
	void	announce();

};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif		// ZOMBIE_HPP
