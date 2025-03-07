#include "Zombie.hpp"

// heap allocation
Zombie *newZombie(std::string name) {
  Zombie *zombie = new Zombie(name);

  return zombie;
}
