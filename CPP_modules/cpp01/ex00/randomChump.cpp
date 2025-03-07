#include "Zombie.hpp"

// stack allocation
void randomChump(std::string name) {
  Zombie zombie(name);
  zombie.announce();
}
