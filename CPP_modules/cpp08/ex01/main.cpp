#include "Span.hpp"

#include <exception>
#include <iostream>

int main() {
  {
    Span sp(5);

    try {
      sp.addNumber(6);
      sp.addNumber(3);
      sp.addNumber(17);
      sp.addNumber(9);
      sp.addNumber(11);
      //  sp.addNumber(11);

      std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  {
    srand(time(NULL));
    int size = 10000;
    Span sp(size);
    try {
      while (size--) {
        sp.addNumber(rand() % 10000);
      }

      std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}