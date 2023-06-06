#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string inputName) : name (inputName)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& inputWeapon)
{
	this->mWeapon = &inputWeapon;
}

void HumanB::attack() const
{
	if (!this->mWeapon)
	{
		std::cout << this->name << " has no weapon!" << std::endl;
		return;
	}
	std::cout << this->name << " attacks with their " << this->mWeapon->getType() << std::endl;
}
