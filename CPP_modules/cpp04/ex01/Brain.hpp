#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define BRAIN_FART "Derp"

class Brain
{
private:
	std::string ideas_[100];

public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& src);
	~Brain();

	std::string	getIdeas() const;
	void		setIdeas(const std::string& ideas);
};

#endif