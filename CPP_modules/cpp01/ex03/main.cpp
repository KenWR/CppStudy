#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    Weapon club2 = Weapon("non binary gun");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    jim.setWeapon(club2);
    jim.attack();
    club2.setType("some other type of club");
    jim.attack();
  }
  return 0;
}