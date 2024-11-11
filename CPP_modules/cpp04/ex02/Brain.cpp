#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
	std::cout << "\033[33mBrain constructor works done\033[0m" << std::endl;

	for(size_t i = 0; i < this->ideas_->size(); ++i) {
		ideas_[i] = BRAIN_FART;
	}
}

Brain::Brain(const Brain& copy)
{
	std::cout << "\033[33mBrain copy constructor works done\033[0m" << std::endl;

	for(size_t i = 0; i < this->ideas_->size(); ++i) {
		ideas_[i] = copy.ideas_[i];
	}
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "\033[33mBrain assignment operator works done\033[0m" << std::endl;
	
	if (this == &src) return *this;

	for(size_t i = 0; i < this->ideas_->size(); ++i) {
		ideas_[i] = src.ideas_[i];
	}

	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[33mBrain destructor works done\033[0m" << std::endl;
}
