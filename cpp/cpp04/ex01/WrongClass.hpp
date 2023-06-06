#ifndef WRONGCLASS_HPP
#define WRONGCLASS_HPP

#include <string>
#include "Brain.hpp"

class WrongAnimal {
public :
	WrongAnimal ();
	WrongAnimal (WrongAnimal const &);
	WrongAnimal& operator= (WrongAnimal const &);
	~WrongAnimal ();

	void			makeSound() const;
	std::string		getType() const;

protected :
	std::string	type;
	Brain*		_Brain;
};

class WrongCat : public WrongAnimal {
public :
	WrongCat ();
	WrongCat (const WrongCat&);
	WrongCat& operator= (const WrongCat&);
	~WrongCat ();

	void		makeSound() const;
	std::string	get_idea(int) const;
	void		set_idea(std::string idea, int index);
};

#endif		// WRONGCLASS_HPP
