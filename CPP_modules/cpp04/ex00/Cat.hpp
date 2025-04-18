#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

#include <string>

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &copy);
  Cat &operator=(const Cat &src);
  virtual ~Cat();

  void makeSound() const;
};

#endif