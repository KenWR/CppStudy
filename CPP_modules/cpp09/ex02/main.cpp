#include "PmergeMe.hpp"

#include <iostream>
#include <list>
#include <vector>

bool IsPositiveSequence(const std::vector<int> &vec);
void PrintContainer(const std::vector<int> &vec);
void PrintContainer(const std::list<int> &lst);
void MergeSortVector(std::vector<int> &vec, int left, int right);
void MergeVector(std::vector<int> &vec, int left, int mid, int right);

int main(int argc, char **argv) {
  std::vector<int> vec;
  std::vector<int> lst;

  for (int i = 1; i < argc; ++i) {
    int number = atoi(argv[i]);
    vec.push_back(number);
    lst.push_back(number);
  }

  if (IsPositiveSequence(vec) == false) {
    std::cerr << "Input numbers are not positive integer sequence\n";
  }

  PrintContainer(vec);
  PrintContainer(lst);
  MergeSortVector(vec, 0, vec.size() - 1);
  PrintContainer(vec);
}

void MergeSortVector(std::vector<int> &vec, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  MergeSortVector(vec, left, mid);
  MergeSortVector(vec, mid + 1, right);
  MergeVector(vec, left, mid, right);
}

void MergeVector(std::vector<int> &vec, int left, int mid, int right) {
  std::vector<int> vec_temp;

  int index_left = left;
  int index_right = mid + 1;
  while (index_left <= mid && index_right <= right) {
    if (vec[index_left] < vec[index_right]) {
      vec_temp.push_back(vec[index_left++]);
    } else {
      vec_temp.push_back(vec[index_right++]);
    }
  }

  while (index_left <= mid) {
    vec_temp.push_back(vec[index_left++]);
  }
  while (index_right <= right) {
    vec_temp.push_back(vec[index_right++]);
  }

  for (size_t i = 0; i < vec_temp.size(); ++i) {
    vec[left + i] = vec_temp[i];
  }
}

void MergeList(std::list<int> &lst, int left, int mid, int right) {
  // std::list<int> lst_temp;

  // int index_left = left;
  // int index_right = mid + 1;
  // std::list<int>::iterator iter = lst.begin();
  // while (index_left <= mid && index_right <= right) {
  //   if (lst.begin() + index_left < vec[index_right]) {
  //     vec_temp.push_back(vec[index_left++]);
  //   } else {
  //     vec_temp.push_back(vec[index_right++]);
  //   }
  // }

  // while (index_left <= mid) {
  //   vec_temp.push_back(vec[index_left++]);
  // }
  // while (index_right <= right) {
  //   vec_temp.push_back(vec[index_right++]);
  // }

  // for (size_t i = 0; i < vec_temp.size(); ++i) {
  //   vec[left + i] = vec_temp[i];
  // }
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