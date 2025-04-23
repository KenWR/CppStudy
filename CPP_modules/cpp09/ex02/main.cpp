#include "PmergeMe.hpp"

#include <ctime>
#include <iostream>
#include <list>
#include <vector>

bool IsPositiveSequence(const std::vector<int> &vec);
void PrintContainer(const std::vector<int> &vec);
void PrintContainer(const std::list<int> &lst);

int main(int argc, char **argv) {
  std::vector<int> vec;
  std::list<int> lst;

  for (int i = 1; i < argc; ++i) {
    int number = atoi(argv[i]);
    vec.push_back(number);
    lst.push_back(number);
  }

  if (IsPositiveSequence(vec) == false) {
    std::cerr << "Input numbers are not positive integer sequence\n";
  }

  PrintContainer(vec);
  // std::cout << std::time(nullptr) << '\n';
  PmergeMe::MergeInsertionSortVector(vec);
  // std::cout << std::time(nullptr) << '\n';
  PrintContainer(vec);
  PmergeMe::PrintComaprison();

  PrintContainer(lst);
  // std::cout << std::time(nullptr) << '\n';
  PmergeMe::MergeInsertionSortList(lst);
  // std::cout << std::time(nullptr) << '\n';
  PrintContainer(lst);
}

// Tools

void PrintContainer(const std::vector<int> &vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << '\n';
}

void PrintContainer(const std::list<int> &lst) {
  std::list<int>::const_iterator iter = lst.begin();
  for (; iter != lst.end(); ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << '\n';
}

bool IsPositiveSequence(const std::vector<int> &vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    if (vec[i] < 0) {
      return false;
    }
    for (size_t j = i + 1; j < vec.size(); ++j) {
      if (vec[i] == vec[j]) {
        return false;
      }
    }
  }
  return true;
}