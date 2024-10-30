#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap {
public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();

	void printAttack(const std::string& name, const std::string& target, unsigned int damage);
	void printTakeDamage(const std::string& name, unsigned int damage);
	void printBeRepaired(const std::string& name, unsigned int damage);
	void printNeutralized(const std::string& name);
	void printNotWorking(const std::string& name);
	void printNotEnoughEnergy(const std::string& name);
};

#endif