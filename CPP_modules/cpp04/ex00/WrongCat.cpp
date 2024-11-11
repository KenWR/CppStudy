#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "\033[33mWrongCat constructor works done\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy.getType())
{
	std::cout << "\033[33mWrongCat copy constructor works done\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "\033[33mWrongCat assignment operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->type_ = src.type_;

	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[33mWrongCat destructor works done\033[0m" << std::endl;
}


void WrongCat::makeSound() const
{
	std::cout << "Yaooooong" << std::endl;
}
