#include <iostream>

double devide(double lhs, double rhs) {
  if (!rhs) throw "Divide by zero";

  return (lhs / rhs);
}

int main() {
  double lhs, rhs;

  std::cout << "Enter a number: " << std::endl;
  std::cin >> lhs;
  std::cout << "Enter another number: " << std::endl;
  std::cin >> rhs;

  std::cout << "Result: " << devide(lhs, rhs) << std::endl;

  return 0;
}
