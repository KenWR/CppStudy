#include "Ice.hpp"
#include "ICharacter.hpp"

#include <iostream>

Ice::Ice() : AMateria(ICE)
{
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
}

Ice& Ice::operator=(const Ice& src)
{
	if (this == &src) return *this;

	return *this;
}

Ice::~Ice()
{
}


AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}