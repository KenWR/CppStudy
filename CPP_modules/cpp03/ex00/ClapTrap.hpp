#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

#define PRINT_CLAPTRAP_ATTACK(name, target, damage) \
	std::cout << "ClapTrap " << (name) << " attacks " << (target) \
              << ", causing " << (damage) << " points of damage!" << std::endl;

#define PRINT_CLAPTRAP_TAKEDAMAGE(name, damage) \
	std::cout << "ClapTrap " << (name) << " take " << (damage) \
			  << " points of damage!" << std::endl;

#define PRINT_CLAPTRAP_BEREPAIRED(name, damage) \
	std::cout << "ClapTrap " << (name) << " is repaired " << (damage) \
			  << " points of durability!" << std::endl;

#define PRINT_CLAPTRAP_NEUTRALIIZED(name) \
	std::cout << "ClapTrap " << (name) << " is neutralized!" << std::endl;

#define PRINT_CLAPTRAP_NOTWORKING(name) \
	std::cout << "ClapTrap " << (name) << " is not working..." << std::endl;

#define PRINT_NOT_ENOUGH_ENERGY(name) \
	std::cout << "ClapTrap " << (name) << " do not have enough energy" << std::endl;


class ClapTrap {
private:
	std::string 	name_;
	unsigned int	hit_points_;	// represent the health of the ClapTrap
	unsigned int	energy_points_;
	unsigned int	attack_damage_;

	ClapTrap();

public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& src);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif