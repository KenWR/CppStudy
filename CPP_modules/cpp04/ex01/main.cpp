#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	Animal* animals[10];
	for(size_t i = 0; i < 10; ++i) {
		if (i < 10 / 2) animals[i] = new Dog();
		else 			animals[i] = new Cat();
	}

	for(size_t i = 0; i < 10; ++i) {
		animals[i]->makeSound();
		delete animals[i];
	}

	return 0;
}
