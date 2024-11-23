#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), 
	hit_points_(10), 
	energy_points_(10), 
	attack_damage_(0)
{
	std::cout << "\033[33mClapTrap " << this->name_ 
		<< " Constructor works done\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage) 
	: name_(name),
	hit_points_(hit_points),
	energy_points_(energy_points),
	attack_damage_(attack_damage) 
{
	std::cout << "\033[33mClapTrap " << this->name_ 
		<< " Parameter constructor works done\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
	: name_(copy.name_), 
	hit_points_(copy.hit_points_), 
	energy_points_(copy.energy_points_),
	attack_damage_(copy.attack_damage_) 
{
	std::cout << "\033[33mClapTrap " << this->name_ 
		<< " Copy constructor works done\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) 
{
	std::cout << "\033[33mClapTrap " << this->name_ 
		<< " assignment operator works done\033[0m" << std::endl;

	if (this == &src) return *this;

	this->name_ = src.name_;
	this->hit_points_ = src.hit_points_;
	this->energy_points_ = src.energy_points_;
	this->attack_damage_ = src.attack_damage_;

	return *this;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "\033[33mClapTrap " << this->name_ 
		<< " DESTRUCTOR works done\033[0m" << std::endl;
}

void	ClapTrap::attack(const std::string& target) 
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

void	ClapTrap::takeDamage(unsigned int amount) 
{
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

void	ClapTrap::beRepaired(unsigned int amount) 
{
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

void ClapTrap::printAttack(const std::string& name, const std::string& target, unsigned int damage) 
{
	std::cout << "ClapTrap " << (name) << " attacks " << (target) \
              << ", causing " << (damage) << " points of damage!" << std::endl;
}

void ClapTrap::printTakeDamage(const std::string& name, unsigned int damage) 
{
	std::cout << "ClapTrap " << (name) << " take " << (damage) \
			  << " points of damage!" << std::endl;}

void ClapTrap::printBeRepaired(const std::string& name, unsigned int damage) 
{
	std::cout << "ClapTrap " << (name) << " is repaired " << (damage) \
			  << " points of durability!" << std::endl;
}

void ClapTrap::printNeutralized(const std::string& name) 
{
	std::cout << "ClapTrap " << (name) << " is neutralized!" << std::endl;
}

void ClapTrap::printNotWorking(const std::string& name) 
{
	std::cout << "ClapTrap " << (name) << " is not working..." << std::endl;
}

void ClapTrap::printNotEnoughEnergy(const std::string& name)
{
	std::cout << "ClapTrap " << (name) << " do not have enough energy" << std::endl;
}

