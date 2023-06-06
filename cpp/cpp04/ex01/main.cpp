#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongClass.hpp"
#include <iostream>

#define NUMBER_OF_ANIMALS 100

int	main()
{
	const	Animal* j = new Dog ();
	const	Animal* i = new Cat ();

	delete j;
	delete i;

	std::cout << "\n\tMy tests:" << std::endl;

	Animal* allAnimals[NUMBER_OF_ANIMALS];

	for (int x = 0; x < NUMBER_OF_ANIMALS; x++)
	{
		if (x < NUMBER_OF_ANIMALS / 2)
			allAnimals[x] = new Dog();
		else
			allAnimals[x] = new Cat();
	}

	allAnimals[1]->makeSound();
	allAnimals[51]->makeSound();

	for (int x = 0; x < NUMBER_OF_ANIMALS; x++)
	{
		std::cout << "Round " << x << "!" << std::endl;
		delete allAnimals[x];
	}

	Dog b;
	b.set_idea("number 14", 14);
	Dog c (b);

	std::cout << "b idea: " << b.get_idea(14) << std::endl;
	std::cout << "c idea: " << c.get_idea(14) << std::endl;;

	/*		
		############	############	############	############	############
		############	Uncomment code below to show shallow copy 		############
		############													############
		############	        PROGRAM WILL CRASH!!!					############
		############													############
		############	############	############	############	############
	*/

	// std::cout << "\n\tNormal copies are deep.\n " << std::endl;

	// Cat*	normalcat = new Cat();
	// normalcat->set_idea("Idea number zero!", 0);
	// Cat		normalcat1 (*normalcat);

	// std::cout << "\nnormalcat1 has one idea: "<< normalcat1.get_idea(0) << std::endl;
	// delete normalcat;
	// std::cout << "\nnormalcat1 still has one idea: " << normalcat1.get_idea(0) << std::endl;

	// std::cout << "\n\tWrongCat copies are shallow:\n" << std::endl;

	// WrongCat* normalwrongcat = new WrongCat;
	// normalwrongcat->set_idea("Idea number zero!", 0);
	// WrongCat shallowwrongcat (*normalwrongcat);
	// std::cout << "\nshallowwrongcat shares his idea with normalwrongcat: "<< shallowwrongcat.get_idea(0) << std::endl;
	// delete normalwrongcat;
	// std::cout << "\nshallowwrongcat idea is bugged: " << shallowwrongcat.get_idea(0) << std::endl;
	return 0;
}
