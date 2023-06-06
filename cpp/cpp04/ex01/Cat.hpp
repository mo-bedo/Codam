#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public :
	Cat ();
	Cat (const Cat&);
	Cat& operator= (Cat const&);
	~Cat ();
	
	void		makeSound() const;

	std::string	get_idea(int) const;
	void		set_idea(std::string idea, int index);

private:
	Brain*	_Brain;
};

#endif 		// CAT_HPP
