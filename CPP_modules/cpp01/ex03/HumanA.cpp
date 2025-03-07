#include "HumanA.hpp"
#include <iostream>
#include <string>

void HumanA::attack(void) {
  std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
            << std::endl;
}

void HumanA::setWeapon(Weapon weapon) { this->weapon_ = weapon; }

HumanA::HumanA(std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {}

HumanA::HumanA(const HumanA &copy) : weapon_(copy.weapon_) { *this = copy; }

HumanA &HumanA::operator=(const HumanA &src) {
  if (this != &src) {
    this->weapon_ = src.weapon_;
    this->name_ = src.name_;
  }

  return *this;
}

HumanA::~HumanA() {}