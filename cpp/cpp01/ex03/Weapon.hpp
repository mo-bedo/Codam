#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public :
	Weapon(std::string);
	~Weapon();
	const std::string	getType();
	void				setType(std::string);
private :
	std::string	type;
};

#endif
