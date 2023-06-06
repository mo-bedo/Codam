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
	void	announce () const;
};

Zombie*	zombieHorde (int N, std::string name);

#endif		// ZOMBIE_HPP
