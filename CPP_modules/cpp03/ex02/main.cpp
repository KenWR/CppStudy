#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap A("A");
	ScavTrap B("B");

	A.attack("B");
	A.takeDamage(5);
	A.beRepaired(5);

	B.guardGate();

	B.attack("A");
	A.takeDamage(20);
	B.takeDamage(5);
	B.beRepaired(5);
}

