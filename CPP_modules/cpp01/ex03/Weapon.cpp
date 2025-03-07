#include "Weapon.hpp"
#include <iostream>

const std::string &Weapon::getType(void) { return this->type_; }

void Weapon::setType(std::string type) { this->type_ = type; }

Weapon::Weapon() {}

Weapon::Weapon(std::string type) { this->setType(type); }

Weapon::Weapon(const Weapon &copy) { *this = copy; }

Weapon &Weapon::operator=(const Weapon &src) {
  if (this != &src) {
    this->type_ = src.type_;
  }

  return (*this);
}

Weapon::~Weapon() {}
