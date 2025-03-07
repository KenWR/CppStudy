#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl
            << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger"
            << std::endl
            << "I really do!" << std::endl
            << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl
            << "I cannot believe adding extra bacon costs more money."
            << std::endl
            << "You didn’t put enough bacon in my burger!" << std::endl
            << "If you did, I wouldn’t be asking for more!" << std::endl
            << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl
            << "I think I deserve to have some extra bacon for free."
            << std::endl
            << "I’ve been coming for years whereas you started working here "
               "since last month."
            << std::endl
            << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl
            << "This is unacceptable! I want to speak to the manager now."
            << std::endl
            << std::endl;
}

int Harl::levelToInt(std::string level) {
  const std::string levels[LEVEL_NUM] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int i = 0;
  while (i < LEVEL_NUM) {
    if (level == levels[i])
      break;
    ++i;
  }
  return (i);
}

void Harl::complain(std::string level) {
  int i = levelToInt(level);
  switch (i) {
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
    break;
  case 0:
    this->debug();
    __attribute__((fallthrough));
  case 1:
    this->info();
    __attribute__((fallthrough));
  case 2:
    this->warning();
    __attribute__((fallthrough));
  case 3:
    this->error();
    break;
  }
}

Harl::Harl() {}

Harl::Harl(const Harl &copy) { *this = copy; }

Harl &Harl::operator=(const Harl &src) {
  if (this != &src) {
  }

  return (*this);
}

Harl::~Harl() {}
