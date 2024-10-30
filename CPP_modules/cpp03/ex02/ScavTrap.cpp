#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(const std::string& name) 
	: ClapTrap(name, 100, 50, 20) { 
	std::cout << "\033[33mScavTrap " << this->name_ 
		  	  << " Constructor called\033[0m" << std::endl;
} 

ScavTrap::ScavTrap(const ScavTrap& copy)
	: ClapTrap(copy.name_, copy.energy_points_, copy.hit_points_, copy.attack_damage_) {
	std::cout << "\033[33mScavTrap " << this->name_ 
			  << " Copy constructor called\033[0m" << std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	std::cout << "\033[33mScavTrap " << this->name_ 
			  << " Align operator called\033[0m" << std::endl;

	if (this == &src) return *this;

	this->name_ = src.name_;
	this->hit_points_ = src.hit_points_;
	this->energy_points_ = src.energy_points_;
	this->attack_damage_ = src.attack_damage_;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "\033[33mScavTrap "  << this->name_ 
			  << " Destructor called\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->hit_points_ == 0) {
		printNotWorking(this->name_);
		return;
	}
	if (this->energy_points_ == 0) {
		printNotEnoughEnergy(this->name_);
		return;
	}

	printAttack(this->name_, target, this->attack_damage_);
	this->energy_points_--;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->hit_points_ == 0) {
		printTakeDamage(this->name_, amount);
		return;
	}
	if (amount >= this->hit_points_) {
		printTakeDamage(this->name_, amount);
		printNeutralized(this->name_);
		this->hit_points_ = 0;
		return;
	}

	printTakeDamage(this->name_, amount);
	this->hit_points_ -= amount;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->hit_points_ == 0) {
		printNotWorking(this->name_);
		return;
	}
	if (this->energy_points_ == 0) {
		printNotEnoughEnergy(this->name_);
		return;
	}
	if (amount > 10 || this->hit_points_ + amount > 10) {
		printBeRepaired(this->name_, amount);
		this->energy_points_--;
		this->hit_points_ = 10;	
		return;
	}

	printBeRepaired(this->name_, amount);
	this->energy_points_--;
	this->hit_points_ += amount;
}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap "  << this->name_ 
			  << " is now on gate mode! YOU FXXKED UP!" << std::endl;
}


void ScavTrap::printAttack(const std::string& name, const std::string& target, unsigned int damage) {
	std::cout << "ScavTrap " << (name) << " attacks " << (target) \
              << ", causing " << (damage) << " points of damage!" << std::endl;
}

void ScavTrap::printTakeDamage(const std::string& name, unsigned int damage) {
	std::cout << "ScavTrap " << (name) << " take " << (damage) \
			  << " points of damage!" << std::endl;}

void ScavTrap::printBeRepaired(const std::string& name, unsigned int damage) {
	std::cout << "ScavTrap " << (name) << " is repaired " << (damage) \
			  << " points of durability!" << std::endl;
}

void ScavTrap::printNeutralized(const std::string& name) {
	std::cout << "ScavTrap " << (name) << " is neutralized!" << std::endl;
}

void ScavTrap::printNotWorking(const std::string& name) {
	std::cout << "ScavTrap " << (name) << " is not working..." << std::endl;
}

void ScavTrap::printNotEnoughEnergy(const std::string& name) {
	std::cout << "ScavTrap " << (name) << " do not have enough energy" << std::endl;
}


