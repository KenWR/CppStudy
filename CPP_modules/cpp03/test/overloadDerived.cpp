#include <iostream>

class Base {
public:
	void print(int) { std::cout << "Base::print(int)" << std::endl; }
	void print(double) { std::cout << "Base::print(double)" << std::endl; }
	void print(int, double) { std::cout << "Base::print(int, double)" << std::endl; }
};

class Derived: public Base {
public:
	using Base::print; // using using keywords
	void print(double) { std::cout << "Derived::print(double)" << std::endl; }
};

int main(void) {
	Derived d;
	d.print(5); // "Base::print(int)"
	d.print(5.0); // "Derived::print(double)"
	d.print(5, 5.0); // now, it works!
}