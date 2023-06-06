#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public :
    ClapTrap();
    ClapTrap(std::string name);
	ClapTrap(ClapTrap const &);
	ClapTrap& operator=(ClapTrap const &);
    virtual ~ClapTrap();

    virtual void    attack(const std::string& target);
    void    		takeDamage(unsigned int amount);
    void    		beRepaired(unsigned int amount);

	void			showStats();

protected :
	std::string _Name;
	int         _HitPoints;
	int         _EnergyPoints;
	int         _AttackDamage;

private :
	void		sayMyName();
};

#endif      // CLAPTRAP_HPP
