#include "DiamondTrap.hpp"

#include <iostream>

int main(void) 
{
	DiamondTrap a("DieAmond");
	DiamondTrap b(a);
	DiamondTrap c("LiveAmond");

	c = a;

	a.whoAmI();
	a.attack("Pinut");
	b.whoAmI();
	b.attack("Pinut");
	b.whoAmI();
	b.takeDamage(50);
	b.takeDamage(50);
}

