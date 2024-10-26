#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), 
	hit_points_(10), 
	energy_points_(10), 
	attack_damage_(0) {
}

ClapTrap::ClapTrap(const ClapTrap& copy)
	: name_(copy.name_), 
	hit_points_(copy.hit_points_), 
	energy_points_(copy.energy_points_),
	attack_damage_(copy.attack_damage_) {
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src) {
		this->name_ = src.name_;
		this->hit_points_ = src.hit_points_;
		this->energy_points_ = src.energy_points_;
		this->attack_damage_ = src.attack_damage_;
	}
	return *this;
}

ClapTrap::~ClapTrap() {

}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << this->name_ <<  "attacks " << target.nam << ", causing " << this->" points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

}

void	ClapTrap::beRepaired(unsigned int amount) {

}

