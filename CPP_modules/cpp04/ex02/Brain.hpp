#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define BRAIN_FART "Derp"

class Brain
{
public:
	std::string ideas_[100];

	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& src);
	~Brain();
};

#endif