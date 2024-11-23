#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Config.hpp"
#include <iostream>

AMateria::AMateria(const std::string& type) : type_(type)
{
	#ifdef LOUD
		std::cout
		<< BOLD << CYAN << "AMateria " << GREEN << "CONSTRUCTOR" << RESET 
		<< std::endl;
	#endif
}

AMateria::AMateria(const AMateria& copy) : type_(copy.type_)
{
	#ifdef LOUD
		std::cout 
		<< BOLD << CYAN << "AMateria " << GREEN << "COPY CONSTRUCTOR" << RESET 
		<< std::endl;
	#endif
}

AMateria& AMateria::operator=(const AMateria& src)
{
	#ifdef LOUD
		std::cout 
		<< BOLD << CYAN << "AMateria " << GREEN << "ALIGN ASSIGNMENT" << RESET 
		<< std::endl;
	#endif

	if (this == &src) return *this;

	this->type_ = src.getType();

	return *this;
}

AMateria::~AMateria()
{
	#ifdef LOUD
		std::cout 
		<< BOLD << CYAN << "AMateria " << RED << "DESTRUCTOR" << RESET 
		<< " << Most Base Class!!!"
		<< std::endl;
	#endif
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
