#include "Cat.hpp"

#include <iostream>

Cat::Cat() : AAnimal(CAT), brain_(new Brain())
{
	std::cout << "\033[33mCat constructor works done\033[0m" << std::endl;
}

Cat::Cat(const Cat& copy) : AAnimal(copy.getType())
{
	std::cout << "\033[33mCat copy constructor works done\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "\033[33mCat assignment operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->type_ = src.type_;

	return *this;
}

Cat::~Cat()
{
	std::cout << "\033[33mCat destructor works done\033[0m" << std::endl;

	delete this->brain_;
}


void Cat::makeSound() const
{
	std::cout << "Yaooooong" << std::endl;
}
