#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name_;

	DiamondTrap();

public:
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap& operator=(const DiamondTrap& src);
	~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();
};

#endif