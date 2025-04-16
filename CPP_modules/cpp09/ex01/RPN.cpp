#include "RPN.hpp"

#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

RPN::RPN() {}

RPN::~RPN() {}

void RPN::calculate(const std::string &token) {
  std::istringstream iss(token);
  char ch;
  while (iss >> ch) {
    if (isdigit(ch)) {
      s_.push(ch - '0');
    } else if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
      if (s_.size() < 2) {
        std::cerr << "Error\n";
        return;
      }

      int operand_right = s_.top();
      s_.pop();
      int operand_left = s_.top();
      s_.pop();

      if (ch == '+') {
        s_.push(operand_left + operand_right);
      } else if (ch == '-') {
        s_.push(operand_left - operand_right);
      } else if (ch == '/') {
        if (operand_right == 0) {
          std::cerr << "Error\n";
          return;
        }
        s_.push(operand_left / operand_right);
      } else if (ch == '*') {
        s_.push(operand_left * operand_right);
      }
    } else {
      std::cerr << "Error\n";
      return;
    }
  }

  if (s_.size() == 1) {
    std::cout << s_.top() << '\n';
    return;
  }

  std::cout << "Error\n";
}