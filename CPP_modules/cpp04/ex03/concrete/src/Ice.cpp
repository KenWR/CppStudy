#include "Ice.hpp"
#include "Config.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria(ICE) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Ice " << GREEN << "CONSTRUCTOR" << RESET
            << " << Most Derived Class!!!" << std::endl;
#endif
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Ice " << GREEN << "COPY CONSTRUCTOR" << RESET
            << " << Most Derived Class!!!" << std::endl;
#endif
}

Ice &Ice::operator=(const Ice &src) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Ice " << GREEN << "ALIGN ASSIGNMENT" << RESET
            << std::endl;
#endif

  if (this == &src)
    return *this;

  return *this;
}

Ice::~Ice() {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Ice " << RED << "DESTRUCTOR" << RESET
            << std::endl;
#endif
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}