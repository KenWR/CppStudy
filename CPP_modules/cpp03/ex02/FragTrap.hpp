#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& src);
	~FragTrap();
	
	void highFivesGuys(void);
};

#endif