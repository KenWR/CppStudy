#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[33mFragTrap " << this->name_ 
		<< " Constructor works done\033[0m" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, 
				this->default_hit_points_, 
				this->default_energy_points_, 
				this->default_attack_damage_)
{
	std::cout << "\033[33mFragTrap " << this->name_ 
		<< " Constructor works done\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
	: ClapTrap(copy.name_, 
				copy.hit_points_, 
				copy.energy_points_, 
				copy.attack_damage_)
{
	std::cout << "\033[33mFragTrap " << this->name_ 
		<< " Copy constructor works done\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "\033[33mFragTrap " << this->name_ 
		<< " Align operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->name_ = src.name_;
	this->hit_points_ = src.hit_points_;
	this->energy_points_ = src.energy_points_;
	this->attack_damage_ = attack_damage_;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[33mFragTrap " << this->name_ 
		<< " Destructor works done\033[0m" << std::endl;
}
	
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name_ 
		<< " looks want high fives!!" << std::endl;
}
