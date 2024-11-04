#include <iostream>

class Base {
public:
	int b_pub = 0;

	void printMember() {
		std::cout << b_pub << std::endl;
		std::cout << b_pro << std::endl;
		std::cout << b_pri << std::endl;
	};
protected:
	int b_pro = 1;
private:
	int b_pri = 2;
};


// public inheritance
class Pub : public Base { 
public: 
	void printBase() {
		std::cout << b_pub << std::endl;
		std::cout << b_pro << std::endl;
		// std::cout << b_pri << std::endl; // inaccessible
	};
};

// protected inheritance
class Pro : protected Base { 
public: 
	void printBase() {
		std::cout << b_pub << std::endl;
		std::cout << b_pro << std::endl;
		// std::cout << b_pri << std::endl; // inaccessible
	};
};

// private inheritance
class Pri : private Base { 
public: 
	void printBase() {
		std::cout << b_pub << std::endl;
		std::cout << b_pro << std::endl;
		// std::cout << b_pri << std::endl; // inaccessible
	};
};


int main() {
	std::cout << "===== print base =====" << std::endl;
	Base base;
	base.printMember();

	std::cout << "===== print pub =====" << std::endl;
	Pub pub;
	pub.printBase();
	pub.b_pub = -1;
	// pub.b_pro = -1; // inaccessible
	// pub.b_pri = -1; // inaccessible

	std::cout << "===== print pro =====" << std::endl;
	Pro pro;
	pro.printBase();
	// pro.b_pub = -1; // inaccessible
	// pro.b_pro = -1; // inaccessible
	// pro.b_pri = -1; // inaccessible

	std::cout << "===== print pri =====" << std::endl;
	Pri pri;
	pri.printBase();
	// pro.b_pub = -1; // inaccessible
	// pro.b_pro = -1; // inaccessible
	// pro.b_pri = -1; // inaccessible

}
