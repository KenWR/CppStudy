#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	// const Animal* a = new Animal(); // compiler error: Animal::makeSound() is pure virtual fuction
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	AAnimal* animals[10];
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
