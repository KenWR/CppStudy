#include <iostream>

class ClapTrap {
public:
  ClapTrap() { std::cout << "ClapTrap constructor" << std::endl; }
};

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap() { std::cout << "ScavTrap constructor" << std::endl; }
};
class FragTrap : virtual public ClapTrap {
public:
  FragTrap() { std::cout << "FragTrap constructor" << std::endl; }
};

class SomeTrap : virtual public ClapTrap {
public:
  SomeTrap() { std::cout << "SomeTrap constructor" << std::endl; }
};

class SomesomeTrap : virtual public ClapTrap {
public:
  SomesomeTrap() { std::cout << "SomesomeTrap constructor" << std::endl; }
};

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap() { std::cout << "DiamondTrap constructor" << std::endl; }
};

int main() {
  DiamondTrap dt;   // call ClapTrap() once
  SomeTrap st;      // call ClapTrap() once
  SomesomeTrap sst; // call ClapTrap() once

  // virtual inheritance call base class constructor only once in single
  // Instantiation
  return 0;
}