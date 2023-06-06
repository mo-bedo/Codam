#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private :
	std::string	name;
	Weapon*		mWeapon;
public :
	HumanB(std::string);
	~HumanB();
	void	setWeapon(Weapon&);
	void 	attack() const;
};

#endif
