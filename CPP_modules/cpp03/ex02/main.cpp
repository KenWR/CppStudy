#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  FragTrap A("A");

  A.attack("B");
  A.beRepaired(10);
  A.highFivesGuys();
  A.takeDamage(100);
  A.beRepaired(10);
  A.attack("B");
  A.takeDamage(10);
}
