#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_FLOOR_ITEMS 100

class Character : public ICharacter {

private :
	AMateria* 	_inventory[4];
	std::string	_name;

	int			_floor_item_idx;
	AMateria*	_item_on_the_floor[MAX_FLOOR_ITEMS];

	void		isFloorFull();
public :
	Character ();
	Character (const std::string &);
	Character (const Character &);
	Character& operator= (const Character &);
	~Character();

	std::string const & getName () const;
	void 				equip (AMateria* m);
	void 				unequip (int idx);
	void 				use (int idx, ICharacter& target);

	void				showInv();
};

#endif 		// CHARACTER_HPP
