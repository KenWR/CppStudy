#include <iostream>

class Base
{
protected:
	int val_;
public:
	Base(int val) : val_(val) {}
	virtual ~Base() {};
	virtual std::string getName() const { return "Base"; }
	int getValue() const { return val_; }
};

class Derived: public Base
{
public:
	Derived(int val) : Base(val) {}
	~Derived() {};
	std::string getName() const { return "Derived"; }
};

int main()
{
    Derived d1(5);
    Derived d2(6);
    Base& b(d2);

    b = d1; // this line is problematic
	// Only d1 copied not d2
}
