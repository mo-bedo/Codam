#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string inputType) : type (inputType)
{
}

Weapon::~Weapon()
{
}

const std::string Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string input)
{
	this->type = input;
}
