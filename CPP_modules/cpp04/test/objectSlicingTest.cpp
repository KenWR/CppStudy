#include <string>
#include <iostream>

class Base
{
protected:
	int val_;
public:
	Base(int val) : val_(val) { std::cout << "Base constructor" << std::endl; }
	virtual ~Base() {};
	virtual std::string getName() const { return "Base"; }
	int getValue() const { return val_; }
};

class Derived: public Base
{
public:
	Derived(int val) : Base(val) { std::cout << "Derived constructor" << std::endl; }
	~Derived() {};
	std::string getName() const { return "Derived"; }
};

// Base passed by value, not reference
// Change to reference is easy way to avoid object slicing
void printName(const Base base) { std::cout << base.getName() << std::endl; }

int main()
{
	Derived derived(5);
	std::cout << derived.getName() << "'s val: " << derived.getValue() << std::endl;
	// Polymorphism
	Base& ref(derived);
	std::cout << ref.getName() << "'s val: " << ref.getValue() << std::endl;
	// Polymorphism
	Base* ptr(&derived);
	std::cout << ptr->getName() << "'s val: " << ptr->getValue() << std::endl;

	// Object Slicing
	// There's no derived in memory, only copied base
	Base base(derived);
	std::cout << base.getName() << "'s val: " << base.getValue() << std::endl;

	printName(derived); // Object slicing happens: Only Base part is copied.
}