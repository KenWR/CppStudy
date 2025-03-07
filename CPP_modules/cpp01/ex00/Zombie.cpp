#include "Zombie.hpp"

#include <iostream>

// public:

void Zombie::announce(void) {
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name_(name) {}

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

// private:
