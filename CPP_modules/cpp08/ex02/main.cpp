#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <stack>
#include <vector>

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl; // 17
  mstack.pop();
  std::cout << mstack.size() << std::endl; // 1
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl; // 5 3 5 737 0
    ++it;
  }
  std::stack<int> s(mstack);

  return 0;
}