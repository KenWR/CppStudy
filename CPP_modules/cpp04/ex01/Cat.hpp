#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

#define CAT "Cat"

class Cat : public Animal
{
private:
	Brain* brain_;
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& src);
	virtual ~Cat();

	void makeSound() const;
};

#endif