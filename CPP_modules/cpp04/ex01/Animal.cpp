#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type_("")
{
	std::cout << "\033[33mAnimal constructor works done\033[0m" << std::endl;
}

Animal::Animal(const std::string& type) : type_(type)
{
	std::cout << "\033[33mAnimal constructor works done\033[0m" << std::endl;
}

Animal::Animal(const Animal& copy) : type_(copy.type_)
{
	std::cout << "\033[33mAnimal copy constructor works done\033[0m" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "\033[33mAnimal align operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->type_ = src.type_;

	return *this;
}

Animal::~Animal()
{
	std::cout << "\033[33mAnimal destructor works done\033[0m" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Grrrr..." << std::endl;
}

std::string Animal::getType() const
{
	return this->type_;
}
