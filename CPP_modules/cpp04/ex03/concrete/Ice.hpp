#ifndef ICE_HPP
#define ICE_HPP

class ICharacter;

#include "AMateria.hpp"

#define ICE "ice"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& src);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif