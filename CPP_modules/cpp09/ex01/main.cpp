#include "RPN.hpp"

#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error\n";
  }
  RPN rpn;

  rpn.calculate(argv[1]);
}