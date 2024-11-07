#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap 
{
private:
	ScavTrap();

public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& src);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();

	void printAttack(const std::string& name, const std::string& target, unsigned int damage);
	void printNotWorking(const std::string& name);
	void printNotEnoughEnergy(const std::string& name);
};

#endif