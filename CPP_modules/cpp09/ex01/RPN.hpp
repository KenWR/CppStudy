#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
  std::stack<int> s_;

  RPN(const RPN &);
  RPN &operator=(const RPN &);

public:
  RPN();
  ~RPN();
  void calculate(const std::string &token);
};

#endif // RPN_HPP