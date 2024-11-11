#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <string>

#define DOG "Dog"

class Dog : public AAnimal
{
private:
	Brain* brain_;
public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& src);
	virtual ~Dog();

	void makeSound() const;
};

#endif