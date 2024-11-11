#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string type_;

public:
	AAnimal();
	AAnimal(const std::string& type);
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal& src);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;

	std::string getType() const;
};

#endif