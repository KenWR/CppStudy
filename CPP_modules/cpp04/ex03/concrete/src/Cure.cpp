#include "Cure.hpp"
#include "Config.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria(CURE) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Cure " << GREEN << "CONSTRUCTOR" << RESET
            << " << Most Derived Class!!!" << std::endl;
#endif
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Cure " << GREEN << "COPY CONSTRUCTOR" << RESET
            << " << Most Derived Class!!!" << std::endl;
#endif
}

Cure &Cure::operator=(const Cure &src) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Cure " << GREEN << "ALIGN ASSIGNMENT" << RESET
            << std::endl;
#endif

  if (this == &src)
    return *this;

  return *this;
}

Cure::~Cure() {
#ifdef LOUD
  std::cout << BOLD << CYAN << "Cure " << RED << "DESTRUCTOR" << RESET
            << std::endl;
#endif
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
