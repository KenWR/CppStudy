#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void) {
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  this->name_ = name;

  std::cout << name << " is wake up!" << std::endl;
}

Zombie::Zombie() {}

Zombie::Zombie(const Zombie &copy) { *this = copy; }

Zombie &Zombie::operator=(const Zombie &src) {
  if (this != &src) {
    this->name_ = src.name_;
  }

  return *this;
}

Zombie::~Zombie() {
  std::cout << this->name_ << " is dead, maybe..." << std::endl;
}
