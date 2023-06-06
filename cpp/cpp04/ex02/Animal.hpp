#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class 	Animal {
public :
	Animal ();
	Animal (Animal const &);
	Animal& operator= (Animal const &);
	virtual ~Animal ();

	virtual void	makeSound() const = 0;

	std::string		getType() const;

protected :
	std::string	type;
};

#endif 		// ANIMAL_HPP
