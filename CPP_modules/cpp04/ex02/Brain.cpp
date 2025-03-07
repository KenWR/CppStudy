#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
  std::cout << "\033[33mBrain constructor works done\033[0m" << std::endl;

  for (size_t i = 0; i < this->ideas_->size(); ++i) {
    ideas_[i] = BRAIN_FART;
  }
}

Brain::Brain(const Brain &copy) {
  std::cout << "\033[33mBrain copy constructor works done\033[0m" << std::endl;

  for (size_t i = 0; i < this->ideas_->size(); ++i) {
    ideas_[i] = copy.getIdeas();
  }
}

Brain &Brain::operator=(const Brain &src) {
  std::cout << "\033[33mBrain assignment operator works done\033[0m"
            << std::endl;

  if (this == &src)
    return *this;

  for (size_t i = 0; i < this->ideas_->size(); ++i) {
    ideas_[i] = src.getIdeas();
  }

  return *this;
}

Brain::~Brain() {
  std::cout << "\033[33mBrain DESTRUCTOR works done\033[0m" << std::endl;
}

std::string Brain::getIdeas() const { return ideas_[0]; }

void Brain::setIdeas(const std::string &ideas) {
  for (size_t i = 0; i < this->ideas_->size(); ++i) {
    ideas_[i] = ideas;
  }
}
