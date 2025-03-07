#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>

Cat::Cat() : Animal(CAT), brain_(new Brain()) {
  std::cout << "\033[33mCat constructor works done\033[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy.getType()) {
  std::cout << "\033[33mCat copy constructor works done\033[0m" << std::endl;

  this->brain_ = new Brain(*copy.brain_);
}

Cat &Cat::operator=(const Cat &src) {
  std::cout << "\033[33mCat assignment operator works done\033[0m" << std::endl;

  if (this == &src)
    return *this;

  this->type_ = src.type_;
  this->brain_ = new Brain(*src.brain_);

  return *this;
}

Cat::~Cat() {
  std::cout << "\033[33mCat DESTRUCTOR works done\033[0m" << std::endl;

  delete this->brain_;
}

void Cat::makeSound() const { std::cout << "Yaooooong" << std::endl; }
