#include <iostream>

void D() {
	std::cout << "Start D\n";
	std::cout << "D throwing int exeption\n";

	throw -1;

	std::cout << "End D\n";
}

void C() {
	std::cout << "Start C\n";
	D();
	std::cout << "End C\n";
}

void B() {
	std::cout << "Start B\n";
	
	try {
		C();
	}
	catch(double) {
		std::cerr << "B caught double exception\n";
	}

	try {}
	catch(int) {
		std::cerr << "B caught int exception\n";
	}
	
	std::cout << "End B\n";
}

void A() {
	std::cout << "Start A\n";

	try {
		B();
	}
	catch(int) {
		std::cerr << "A caught int exception\n";
	}
	catch(double) {
		std::cerr << "A caught double exception\n";
	}
	
	std::cout << "End A\n";
}

int main() {
	std::cout << "Start main\n";

	try {
		A();
	}
	catch(int) {
		std::cerr << "main caught int exception\n";
	}
	std::cout << "End main\n";
}


