#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() 
{ 
	std::cout << "\033[33mScavTrap " << this->name_ 
		<< " Constructor works done\033[0m" << std::endl;
} 

ScavTrap::ScavTrap(const std::string& name) 
	: ClapTrap(name, 
				this->default_hit_points_, 
				this->default_energy_points_, 
				this->default_attack_damage_) 
{ 
	std::cout << "\033[33mScavTrap " << this->name_ 
		<< " Constructor works done\033[0m" << std::endl;
} 

ScavTrap::ScavTrap(const ScavTrap& copy)
	: ClapTrap(copy.name_, copy.energy_points_, copy.hit_points_, copy.attack_damage_) 
{
	std::cout << "\033[33mScavTrap " << this->name_ 
		<< " Copy constructor works done\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) 
{
	std::cout << "\033[33mScavTrap " << this->name_ 
		<< " Align operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->name_ = src.name_;
	this->hit_points_ = src.hit_points_;
	this->energy_points_ = src.energy_points_;
	this->attack_damage_ = src.attack_damage_;

	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "\033[33mScavTrap "  << this->name_ 
			  << " Destructor works done\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string& target) 
{
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

void ScavTrap::guardGate() 
{
	std::cout << "ScavTrap "  << this->name_ 
		<< " is now on gate mode! YOU FXXKED UP!" << std::endl;
}

void ScavTrap::printAttack(const std::string& name, const std::string& target, unsigned int damage) 
{
	std::cout << "ScavTrap " << (name) << " attacks " << (target) \
        << ", causing " << (damage) << " points of damage!" << std::endl;
}

void ScavTrap::printNotWorking(const std::string& name) 
{
	std::cout << "ScavTrap " << (name) << " is not working..." << std::endl;
}

void ScavTrap::printNotEnoughEnergy(const std::string& name) 
{
	std::cout << "ScavTrap " << (name) << " do not have enough energy" << std::endl;
}


