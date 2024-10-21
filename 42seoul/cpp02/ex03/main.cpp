#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a;
	Point b(10, 0, 0);
	Point c(5, 8, 0);

	Point inPoint[9] = { 
		Point(5, 4, 1),
		Point(4, 2, 1),
		Point(6, 2, 1),
		Point(3, 5, 1),
		Point(7, 5, 1),
		Point(5, 3, 1), 
		Point(10, 0, 1),
		Point(),
		Point(5, 8, 1)
	};

	Point outPoint[6] = {
		Point(0, 10, 0),
		Point(12, 0, 0),
		Point(5, -2, 0),
		Point(-3, 3, 0),
		Point(8, 10, 0),
		Point(5, 5, 3)
	};

	std::cout << "내부 점들" << std::endl; 
	for (int i = 0; i < 9; ++i) {
		if (bsp(a, b, c, inPoint[i])) {
			std::cout << "내부" << std::endl; 
		}
		else {
			std::cout << "외부" << std::endl; 
		}
	}

	std::cout << "외부 점들" << std::endl; 
	for (int i = 0; i < 6; ++i) {
		if (bsp(a, b, c, outPoint[i])) {
			std::cout << "내부" << std::endl; 
		}
		else {
			std::cout << "외부" << std::endl; 
		}
	}

	return 0;
}