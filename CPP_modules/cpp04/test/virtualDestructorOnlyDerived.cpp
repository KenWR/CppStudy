#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type_;

public:
	
	WrongAnimal() : type_("")
	{
		std::cout << "\033[33mWrongAnimal constructor works done\033[0m" << std::endl;
	}

	WrongAnimal(const std::string& type) : type_(type)
	{
		std::cout << "\033[33mWrongAnimal constructor works done\033[0m" << std::endl;
	}

	WrongAnimal(const WrongAnimal& copy) : type_(copy.type_)
	{
		std::cout << "\033[33mWrongAnimal copy constructor works done\033[0m" << std::endl;
	}

	WrongAnimal& operator=(const WrongAnimal& src)
	{
		std::cout << "\033[33mWrongAnimal assignment operator works done\033[0m" << std::endl;

		if (this == &src) return *this;

		this->type_ = src.type_;

		return *this;
	}

	// no virtual destructor
	~WrongAnimal()
	{
		std::cout << "\033[33mWrongAnimal destructor works done\033[0m" << std::endl;
	}

	void makeSound() const
	{
		std::cout << "Grrrr..." << std::endl;
	}

	std::string getType() const
	{
		return this->type_;
	}
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat() : WrongAnimal("WrongCat")
	{
		std::cout << "\033[33mWrongCat constructor works done\033[0m" << std::endl;
	}

	WrongCat(const WrongCat& copy) : WrongAnimal(copy.getType())
	{
		std::cout << "\033[33mWrongCat copy constructor works done\033[0m" << std::endl;
	}

	WrongCat& operator=(const WrongCat& src)
	{
		std::cout << "\033[33mWrongCat assignment operator works done\033[0m" << std::endl;

		if (this == &src) return *this;

		this->type_ = src.type_;

		return *this;
	}

	// something wrong in this virtual destructor
	virtual ~WrongCat()
	{
		std::cout << "\033[33mWrongCat destructor works done\033[0m" << std::endl;
	}


	void makeSound() const
	{
		std::cout << "Yaooooong" << std::endl;
	}

};

int main()
{
	WrongAnimal* wj = new WrongCat();

	std::cout << wj->getType() << std::endl;
	wj->makeSound();

	delete wj;	// pointer being freed was not allocated

	return 0;
}
