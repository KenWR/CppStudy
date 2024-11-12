#ifndef CURE_HPP
#define CURE_HPP

class ICharacter;

#include "AMateria.hpp"

#define CURE "cure"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& copy);
	Cure& operator=(const Cure& src);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif