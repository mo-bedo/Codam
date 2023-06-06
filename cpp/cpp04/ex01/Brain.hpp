#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public :
	Brain();
	Brain(const Brain&);
	Brain& operator= (const Brain&);
	~Brain();

	std::string	get_idea(int) const;
	void		set_idea(std::string, int);

private :
	std::string	ideas[100];
};

#endif 		// BRAIN_HPP
