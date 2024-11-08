#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string type_;

public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& src);
	virtual ~WrongAnimal();

	void makeSound() const;

	std::string getType() const;
};

#endif