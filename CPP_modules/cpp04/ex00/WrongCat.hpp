#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#include <string>

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &copy);
  WrongCat &operator=(const WrongCat &src);
  ~WrongCat();

  void makeSound() const;
};

#endif