#include "Character.hpp"
#include <iostream>
#include <stdlib.h>

Character::Character ()  : _name("Poppetje"), _floor_item_idx(0)
{
	std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character (const std::string &name) : _name(name), _floor_item_idx(0)
{
	std::cout << "Character name constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character (const Character &obj) : _floor_item_idx(obj._floor_item_idx)
{
	AMateria* copy_materia;

	this->_name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		if (obj._inventory[i])
		{
			copy_materia = obj._inventory[i]->clone();
			delete obj._inventory[i];
			this->_inventory[i] = copy_materia;
		}
	}
	std::cout << "Character copy constructor called." << std::endl;

}

Character& Character::operator= (const Character &obj)
{
	std::cout << "Character assignment operator called." << std::endl;
	this->_name = obj._name;
	this->_floor_item_idx = obj._floor_item_idx;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = obj._inventory[i];
	return *this;
}

// Checks if Materia's are equiped and deletes them. If 1 Materia is
// equiped in multiple slots it only deletes one.
Character::~Character()
{
	AMateria* memory_addr_materia = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && (this->_inventory[i] != memory_addr_materia))
		{
			memory_addr_materia = this->_inventory[i];
			delete this->_inventory[i];
		}
	}
	memory_addr_materia = NULL;
	for (int i = 0; i < this->_floor_item_idx; i++)
	{
		if (this->_item_on_the_floor[i] && (this->_item_on_the_floor[i] != memory_addr_materia))
		{
			memory_addr_materia = this->_item_on_the_floor[i];
			delete this->_item_on_the_floor[i];
		}
	}
	std::cout << "Character destructor called." << std::endl;
}

std::string const & Character::getName () const
{
	return this->_name;
}

void	Character::isFloorFull()
{
	if (this->_floor_item_idx == MAX_FLOOR_ITEMS)
	{
		std::cout << "The world drowns in floor items. Goodbye." << std::endl;
		exit(1);
	}
}

void Character::equip (AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	this->isFloorFull();
	this->_item_on_the_floor[_floor_item_idx++] = m;
}

void Character::unequip (int idx)
{
	if (idx > 3)
	{
		std::cout << "Cannot find equiqment slot " << idx << std::endl;
		return;
	}
	if (this->_inventory[idx])
	{
		isFloorFull();
		this->_item_on_the_floor[_floor_item_idx++] = this->_inventory[idx];
	}
	std::cout << "Unequiped slot " << idx << std::endl;
	this->_inventory[idx] = NULL;
}

void Character::use (int idx, ICharacter& target)
{
	this->_inventory[idx]->use(target);
}

void Character::showInv()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << "Slot " << i << " has " << this->_inventory[i]->getType()
					  << " equiped." << std::endl;
	}
}
