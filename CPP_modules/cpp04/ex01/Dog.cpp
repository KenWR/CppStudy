#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal(DOG), brain_(new Brain())
{
	std::cout << "\033[33mDog constructor works done\033[0m" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy.getType())
{
	std::cout << "\033[33mDog copy constructor works done\033[0m" << std::endl;

	this->brain_ = new Brain(*copy.brain_);
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "\033[33mDog assignment operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->type_ = src.type_;
	this->brain_ = new Brain(*src.brain_);

	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[33mDog destructor works done\033[0m" << std::endl;

	delete this->brain_;
}

void Dog::makeSound() const
{
	std::cout << "Meong" << std::endl;
}

