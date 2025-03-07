#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_trap", FragTrap::default_hit_points_,
               ScavTrap::default_energy_points_,
               FragTrap::default_attack_damage_),
      name_(name) {
  std::cout << "\033[33mDiamondTrap " << this->name_
            << " Constructor works done\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name_(copy.name_) {
  std::cout << "\033[33mDiamondTrap " << this->name_
            << " Copy constructor works done\033[0m" << std::endl;

  this->name_ = copy.name_;
  this->ClapTrap::name_ = copy.ClapTrap::name_;
  this->hit_points_ = copy.hit_points_;
  this->energy_points_ = copy.energy_points_;
  this->attack_damage_ = copy.attack_damage_;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
  std::cout << "\033[33mDiamondTrap " << this->name_
            << " assignment operator works done\033[0m" << std::endl;

  if (this == &src)
    return *this;

  this->name_ = src.name_;
  this->ClapTrap::name_ = src.ClapTrap::name_;
  this->hit_points_ = src.hit_points_;
  this->energy_points_ = src.energy_points_;
  this->attack_damage_ = src.attack_damage_;

  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "\033[33mDiamondTrap " << this->name_
            << " DESTRUCTOR works done\033[0m" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am DiamondTrap " << this->name_ << " and.... " << "ClapTrap "
            << this->ClapTrap::name_ << std::endl;
}