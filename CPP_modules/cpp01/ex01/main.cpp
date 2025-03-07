#include "Zombie.hpp"
#include <iostream>

int main(void) {
  int N = 3;
  std::string name = "zombie";
  Zombie *zombies = zombieHorde(N, name);

  for (int i = 0; i < N; ++i) {
    zombies->announce();
  }
  delete[] zombies;
  zombies = NULL;
}
