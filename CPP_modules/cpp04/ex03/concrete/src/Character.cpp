#include "Character.hpp"
#include "AMateria.hpp"
#include "Config.hpp"
#include <iostream>

Character::Character(const std::string &name) : ICharacter(), name_(name) {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "Character" << RESET << " " << BOLD << GREEN
            << "CONSTRUCTOR" << RESET << " << Most Derived Class!!!"
            << std::endl;
#endif

  this->inventory_[0] = 0;
  this->inventory_[1] = 0;
  this->inventory_[2] = 0;
  this->inventory_[3] = 0;
}

Character::Character(const Character &copy)
    : ICharacter(copy), name_(copy.name_) {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "Character" << RESET << " " << BOLD << GREEN
            << "COPY CONSTRUCTOR" << RESET << " << Most Derived Class!!!"
            << std::endl;
#endif

  if (copy.inventory_[0])
    this->inventory_[0] = copy.inventory_[0]->clone();
  else
    this->inventory_[0] = 0;

  if (copy.inventory_[1])
    this->inventory_[1] = copy.inventory_[1]->clone();
  else
    this->inventory_[1] = 0;

  if (copy.inventory_[2])
    this->inventory_[2] = copy.inventory_[2]->clone();
  else
    this->inventory_[2] = 0;

  if (copy.inventory_[3])
    this->inventory_[3] = copy.inventory_[3]->clone();
  else
    this->inventory_[3] = 0;
}

Character &Character::operator=(const Character &src) {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "Character" << RESET << " " << BOLD << GREEN
            << "ALIGN ASSIGNMENT" << RESET << std::endl;
#endif

  if (this == &src)
    return *this;

  this->name_ = src.name_;
  if (this->inventory_[0])
    delete this->inventory_[0];
  if (this->inventory_[1])
    delete this->inventory_[1];
  if (this->inventory_[2])
    delete this->inventory_[2];
  if (this->inventory_[3])
    delete this->inventory_[3];

  if (src.inventory_[0])
    this->inventory_[0] = src.inventory_[0]->clone();
  else
    this->inventory_[0] = 0;

  if (src.inventory_[1])
    this->inventory_[1] = src.inventory_[1]->clone();
  else
    this->inventory_[1] = 0;

  if (src.inventory_[2])
    this->inventory_[2] = src.inventory_[2]->clone();
  else
    this->inventory_[2] = 0;

  if (src.inventory_[3])
    this->inventory_[3] = src.inventory_[3]->clone();
  else
    this->inventory_[3] = 0;

  return *this;
}

Character::~Character() {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "Character" << RESET << " " << BOLD << RED
            << "DESTRUCTOR" << RESET << std::endl;
#endif
}

const std::string &Character::getName() const { return this->name_; }

void Character::equip(AMateria *m) {
  if (m == 0)
    return;
  for (size_t i = 0; i < MAX_MATERIA; ++i) {
    if (this->inventory_[i] == 0) {
      this->inventory_[i] = m;
      break;
    }
  }

  return;
}

void Character::unequip(int idx) {
  if (idx < 0 || 3 < idx || this->inventory_[idx] == 0)
    return;

  this->inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || 3 < idx || this->inventory_[idx] == 0)
    return;

  this->inventory_[idx]->use(target);
}
