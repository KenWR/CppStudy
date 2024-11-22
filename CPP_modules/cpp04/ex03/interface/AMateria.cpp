#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

AMateria::AMateria(const std::string& type) : type_(type)
{
}

AMateria::AMateria(const AMateria& copy) : type_(copy.type_)
{
}

AMateria& AMateria::operator=(const AMateria& src)
{
	if (this == &src) return *this;

	this->type_ = src.getType();

	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return this->type_;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Wild MAGIKARP use SPLASH to "<< target.getName() << " !!!" << std::endl
		<< "But nothing happened!" << std::endl;
}
