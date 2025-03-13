#include "Iter.hpp"

#include <iostream>

void addIntOne(int &a) { a += 1; }

void addCharOne(char &c) { c += 1; }

int main() {
  {
    int a[3] = {1, 2, 3};
    ft::iter(a, 3, addIntOne);
    for (size_t i = 0; i < 3; ++i) {
      std::cout << a[i] << " ";
    }
    std::cout << '\n';
  }

  {
    char b[3] = {'a', 'b', 'c'};
    ft::iter(b, 3, addCharOne);
    for (size_t i = 0; i < 3; ++i) {
      std::cout << b[i] << " ";
    }
    std::cout << '\n';
  }
}