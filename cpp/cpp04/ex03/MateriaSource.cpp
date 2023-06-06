#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_stored_materia[i] = NULL;
	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	for (int i = 0; i < 4; i++)
		this->_stored_materia[i] = obj._stored_materia[i];
	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource& MateriaSource::operator= (MateriaSource const &obj)
{
	for (int i = 0; i < 4; i++)
		this->_stored_materia[i] = obj._stored_materia[i];
	std::cout << "MateriaSource assignment operator called." << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	AMateria* memory_addr_materia = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (this->_stored_materia[i] && (this->_stored_materia[i] != memory_addr_materia))
		{
			memory_addr_materia = this->_stored_materia[i];
			delete this->_stored_materia[i];
		}
	}
	std::cout << "MateriaSource destructor called." << std::endl;
}

void		MateriaSource::learnMateria(AMateria* to_learn)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_stored_materia[i])
		{
			this->_stored_materia[i] = to_learn;
			return ;
		}
	}
	std::cout << "No inventory space to store Materia." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_stored_materia[i] && type == this->_stored_materia[i]->getType())
		{
			std::cout << "Created Materia from inventory." << std::endl;
			return this->_stored_materia[i]->clone();
		}
	}
	std::cout << "Unknown Materia type." << std::endl;
	return NULL;
}
