#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type_;

public:
	~WrongAnimal() { std::cout << "WrongAnimal" << std::endl; };

};

class WrongCat : public WrongAnimal
{
public:
	virtual ~WrongCat() { std::cout << "WrongCat" << std::endl; };
};

int main(void)
{
    WrongAnimal* wa = new WrongCat();
    
	delete wa;

    return 0;
}