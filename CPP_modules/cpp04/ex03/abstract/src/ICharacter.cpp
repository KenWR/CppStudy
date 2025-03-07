#include "ICharacter.hpp"
#include "Config.hpp"
#include <iostream>

ICharacter::ICharacter() {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "ICharacter" << RESET << " " << BOLD
            << GREEN << "CONSTRUCTOR" << RESET << std::endl;
#endif
}

ICharacter::ICharacter(const ICharacter &copy) {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "ICharacter" << RESET << " " << BOLD
            << GREEN << "COPY CONSTRUCTOR" << RESET << std::endl;
#endif

  static_cast<void>(copy);
}

ICharacter &ICharacter::operator=(const ICharacter &src) {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "ICharacter" << RESET << " " << BOLD
            << GREEN << "ALIGN ASSIGNMENT" << RESET << std::endl;
#endif

  static_cast<void>(src);
  return *this;
}

ICharacter::~ICharacter() {
#ifdef LOUD
  std::cout << BOLD << UNDERLINE << "ICharacter" << RESET << " " << BOLD << RED
            << "DESTRUCTOR" << RESET << " << Most Base Class!!!" << std::endl;
#endif
}
