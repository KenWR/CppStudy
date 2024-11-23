#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : type_("")
{
	std::cout << "\033[33mAAnimal constructor works done\033[0m" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type_(type)
{
	std::cout << "\033[33mAAnimal constructor works done\033[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type_(copy.type_)
{
	std::cout << "\033[33mAAnimal copy constructor works done\033[0m" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src)
{
	std::cout << "\033[33mAAnimal assignment operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->type_ = src.type_;

	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "\033[33mAAnimal DESTRUCTOR works done\033[0m" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Grrrr..." << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type_;
}
