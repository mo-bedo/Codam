#ifndef	HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private :
	std::string name;
	Weapon&		mWeapon;
public :
	HumanA(std::string, Weapon&);
	~HumanA();
	void attack() const;
};

#endif
