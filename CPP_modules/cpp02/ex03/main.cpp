#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  Point a;
  Point b(10, 0);
  Point c(5, 8);

  Point points[15] = {Point(5, 4),  Point(4, 2),  Point(6, 2),  Point(3, 5),
                      Point(7, 5),  Point(5, 3),  Point(0, 10), Point(12, 0),
                      Point(5, -2), Point(-3, 3), Point(8, 10), Point(5, 5),
                      Point(2, 2),  Point(0, 0),  Point(-1, -1)};

  std::cout << "내부 점들" << std::endl;
  for (int i = 0; i < 15; ++i) {
    if (bsp(a, b, c, points[i]))
      std::cout << "내부에 존재하는 점입니다" << std::endl;
    else
      std::cout << "외부에 존재하는 점입니다" << std::endl;
  }

  return 0;
}