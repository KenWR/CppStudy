#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <string>

class AMateria
{
private:
	AMateria();
protected:
	std::string type_;
	
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& src);
	~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif