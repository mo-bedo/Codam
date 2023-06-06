#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string inputName, Weapon& inputWeapon)
	: name (inputName), mWeapon (inputWeapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->mWeapon.getType() << std::endl;
}
