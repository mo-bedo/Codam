#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {
public :
	Dog ();
	Dog (const Dog&);
	Dog& operator= (const Dog&);
	~Dog ();

	void		makeSound() const;

	std::string	get_idea(int) const;
	void		set_idea(std::string idea, int index);

private :
	Brain*	_Brain;
};

#endif		// DOG_HPP
