#ifndef FT_UTILITY_HPP
#define FT_UTILITY_HPP

#include <iostream>
#include <string>

namespace ft {

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> T min(const T &a, const T &b) { return (a < b) ? a : b; }

template <typename T> T max(const T &a, const T &b) { return (a > b) ? a : b; }

/*
 * According to the compiler's function overloading rules, when calling a
 * function without explicitly specifying template parameters (<>), the compiler
 * will prioritize non-template functions over template functions if both are
 * viable candidates for the function call.
 */

// void swap(int a, int b) { // this swap is wrong.
//   int c = a + b;
//   (void)c;
//   std::cout << "Wrong swap called!\n";
// };

// int min(int a, int b) { // this min is wrong.
//   std::cout << "Wrong min called!\n";
//   return (a > b) ? a : b;
// }

// int max(int a, int b) { // this max is wrong.
//   std::cout << "Wrong max called!\n";
//   return (a < b) ? a : b;
// }

// void swap(std::string a, std::string b) { // this swap is wrong.
//   std::string c = a + b;
//   (void)c;
//   std::cout << "Wrong swap called!\n";
// };

// std::string min(std::string a, std::string b) { // this min is wrong.
//   std::cout << "Wrong min called!\n";
//   return (a > b) ? a : b;
// }

// std::string max(std::string a, std::string b) { // this max is wrong.
//   std::cout << "Wrong max called!\n";
//   return (a < b) ? a : b;
// }

} // namespace ft

#endif