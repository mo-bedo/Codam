#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public :
    ClapTrap();
    ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const &);
	ClapTrap& operator=(ClapTrap const &);
    virtual ~ClapTrap();

    virtual void    attack(const std::string& target);
    void   			takeDamage(unsigned int amount);
    void    		beRepaired(unsigned int amount);

protected :
	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;

};

#endif      // CLAPTRAP_HPP
