#include "easyfind.hpp"

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<int> vec;
  std::list<int> lst;
  std::deque<int> deq;

  for (size_t i = 0; i < 10; ++i) {
    vec.push_back(i);
    lst.push_back(i);
    deq.push_back(i);
  }

  std::vector<int>::iterator vecIter = ft::easyfind(vec, 1);
  std::vector<int>::const_iterator constVecIter = ft::easyfind(vec, 1);
  std::cout << *vecIter << '\n';
  std::cout << *constVecIter << '\n';
  std::list<int>::iterator lstIter = ft::easyfind(lst, 2);
  std::list<int>::const_iterator constLstIter = ft::easyfind(lst, 2);
  std::cout << *lstIter << '\n';
  std::cout << *constLstIter << '\n';
  std::deque<int>::iterator deqIter = ft::easyfind(deq, 3);
  std::deque<int>::const_iterator constDeqIter = ft::easyfind(deq, 3);
  std::cout << *deqIter << '\n';
  std::cout << *constDeqIter << '\n';
}