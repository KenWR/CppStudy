#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Harl harl;

  if (argc != 2) {
    std::cout << "Wrong argument" << std::endl;
    return (0);
  }
  std::string level(argv[1]);
  harl.complain(level);
}