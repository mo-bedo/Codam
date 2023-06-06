#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongClass.hpp"
#include <iostream>

#define NUMBER_OF_ANIMALS 10

int	main()
{

	Dog b;
	Dog c = b;

	b.makeSound();
	c.makeSound();

	Animal* allAnimals[NUMBER_OF_ANIMALS];

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i < NUMBER_OF_ANIMALS / 2)
			allAnimals[i] = new Dog();
		else
			allAnimals[i] = new Cat();
	}

	allAnimals[1]->makeSound();
	allAnimals[6]->makeSound();

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		std::cout << "Round " << i << "!" << std::endl;
		delete allAnimals[i];
	}


	// This code won't work because Animal is an abstract class (so you cannot instanciate the class).
	// Animal* x = new Animal();
	// Animal d;

	return 0;
}
