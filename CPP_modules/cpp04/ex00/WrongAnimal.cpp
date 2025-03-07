#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type_("") {
  std::cout << "\033[33mWrongAnimal constructor works done\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type_(type) {
  std::cout << "\033[33mWrongAnimal constructor works done\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type_(copy.type_) {
  std::cout << "\033[33mWrongAnimal copy constructor works done\033[0m"
            << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
  std::cout << "\033[33mWrongAnimal assignment operator works done\033[0m"
            << std::endl;

  if (this == &src)
    return *this;

  this->type_ = src.type_;

  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "\033[33mWrongAnimal DESTRUCTOR works done\033[0m" << std::endl;
}

void WrongAnimal::makeSound() const { std::cout << "Grrrr..." << std::endl; }

std::string WrongAnimal::getType() const { return this->type_; }
