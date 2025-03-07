#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

#define DOG "Dog"

class Dog : public Animal {
private:
  Brain *brain_;

public:
  Dog();
  Dog(const Dog &copy);
  Dog &operator=(const Dog &src);
  virtual ~Dog();

  void makeSound() const;
};

#endif