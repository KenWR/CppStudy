#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "\033[33mDog constructor works done\033[0m" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy.getType())
{
	std::cout << "\033[33mDog copy constructor works done\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "\033[33mDog assignment operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->type_ = src.type_;

	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[33mDog DESTRUCTOR works done\033[0m" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Meong" << std::endl;
}

