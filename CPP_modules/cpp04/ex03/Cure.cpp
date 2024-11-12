#include "Cure.hpp"
#include "ICharacter.hpp"

#include <iostream>

Cure::Cure() : AMateria(CURE)
{
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
}

Cure& Cure::operator=(const Cure& src)
{
	if (this == &src) return *this;

	return *this;
}

Cure::~Cure()
{
}


AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
