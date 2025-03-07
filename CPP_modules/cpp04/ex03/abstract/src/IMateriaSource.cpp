#include "IMateriaSource.hpp"
#include "Config.hpp"
#include <iostream>

IMateriaSource::IMateriaSource() {
#ifdef LOUD
  std::cout << BOLD << CYAN << "IMateriaSource " << GREEN << "CONSTRUCTOR"
            << RESET << std::endl;
#endif
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "IMateriaSource " << GREEN << "COPY CONSTRUCTOR"
            << RESET << std::endl;
#endif

  static_cast<void>(copy);
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &src) {
#ifdef LOUD
  std::cout << BOLD << CYAN << "IMateriaSource " << GREEN << "ALIGN ASSIGNMENT"
            << RESET << std::endl;
#endif

  static_cast<void>(src);
  return *this;
}

IMateriaSource::~IMateriaSource() {
#ifdef LOUD
  std::cout << BOLD << CYAN << "IMateriaSource " << RED << "DESTRUCTOR" << RESET
            << " << Most Base Class!!!" << std::endl;
#endif
}
