#include <iostream>

class ClapTrap { 
public:
	void attack() { std::cout << "ClapTrap attack" << std::endl; }
};

class ScavTrap : virtual public ClapTrap  { 
public:
	void callAttack() { attack(); } // call FragTrap::attack() by cross delegation
	//void attack() { std::cout << "ScavTrap attack" << std::endl; }
};
class FragTrap : virtual public ClapTrap  { 
public:	
	void attack() { std::cout << "FragTrap attack" << std::endl; }
};

class DiamondTrap : public ScavTrap, public FragTrap { 
public:	
	// void attack() { std::cout << "DiamondTrap attack" << std::endl; }
};

int main() {
	DiamondTrap dt;
	dt.attack();
	
	return 0;
}