#include "HumanB.hpp"
#include <iostream>
#include <string>

void HumanB::attack(void) {
  if (this->weapon_) {
    std::cout << this->name_ << " attacks with their "
              << this->weapon_->getType() << std::endl;
  } else {
    std::cout << this->name_ << " attacks with their fist" << std::endl;
  }
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon_ = &weapon; }

HumanB::HumanB() {
  this->name_ = "";
  this->weapon_ = NULL;
}

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

HumanB::HumanB(std::string name, Weapon &weapon)
    : name_(name), weapon_(&weapon) {}

HumanB::HumanB(const HumanB &copy) { *this = copy; }

HumanB &HumanB::operator=(const HumanB &src) {
  if (this != &src) {
    this->weapon_ = src.weapon_;
    this->name_ = src.name_;
  }

  return *this;
}

HumanB::~HumanB() {}