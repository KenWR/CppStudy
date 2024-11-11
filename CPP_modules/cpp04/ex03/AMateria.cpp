#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type_(type)
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
