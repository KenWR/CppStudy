#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), 
	hit_points_(10), 
	energy_points_(10), 
	attack_damage_(0) {
		std::cout << "\033[33m" << this->name_ << " Constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
	: name_(copy.name_), 
	hit_points_(copy.hit_points_), 
	energy_points_(copy.energy_points_),
	attack_damage_(copy.attack_damage_) {
		std::cout << "\033[33m" << this->name_ << " Copy constructor called\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	std::cout << "\033[33m" << this->name_ << " Align operator called\033[0m" << std::endl;

	if (this == &src) return *this;

	this->name_ = src.name_;
	this->hit_points_ = src.hit_points_;
	this->energy_points_ = src.energy_points_;
	this->attack_damage_ = src.attack_damage_;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "\033[33m" << this->name_ << " Destructor called\033[0m" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->hit_points_ == 0) {
		PRINT_CLAPTRAP_NOTWORKING(this->name_);
		return;
	}
	if (this->energy_points_ == 0) {
		PRINT_NOT_ENOUGH_ENERGY(this->name_);
		return;
	}

	PRINT_CLAPTRAP_ATTACK(this->name_, target, this->attack_damage_);
	this->energy_points_--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points_ == 0) {
		PRINT_CLAPTRAP_TAKEDAMAGE(this->name_, amount);
		return;
	}
	if (amount >= this->hit_points_) {
		PRINT_CLAPTRAP_TAKEDAMAGE(this->name_, amount);
		PRINT_CLAPTRAP_NEUTRALIIZED(this->name_)
		this->hit_points_ = 0;
		return;
	}

	PRINT_CLAPTRAP_TAKEDAMAGE(this->name_, amount);
	this->hit_points_ -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points_ == 0) {
		PRINT_NOT_ENOUGH_ENERGY(this->name_);
		return;
	}
	if (amount > 10 || this->hit_points_ + amount > 10) {
		PRINT_CLAPTRAP_BEREPAIRED(this->name_, amount);
		this->energy_points_--;
		this->hit_points_ = 10;	
		return;
	}

	PRINT_CLAPTRAP_BEREPAIRED(this->name_, amount);
	this->energy_points_--;
	this->hit_points_ += amount;
}

