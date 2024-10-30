#include "ClapTrap.hpp"

int main(void) {
	ClapTrap A("A");
	ClapTrap B("B");

	A.attack("B");
	A.takeDamage(10);
	A.beRepaired(3);
	A.attack("B");
	A.takeDamage(1);
	A.attack("B");
	A.takeDamage(10);
	A.takeDamage(10);

	for (int i = 0; i < 11; ++i) {
		B.attack("A");
	}
}

