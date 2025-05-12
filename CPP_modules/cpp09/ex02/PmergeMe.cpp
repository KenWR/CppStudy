#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

// clang-format off
static void BinaryInsertionVector(std::vector<std::pair<int, int> > &vec, std::pair<int, int> &value);
static void BinaryInsertionVector(std::vector<int> &vec, int value);
// static void BinaryInsertionList(std::list<int> &lst, std::pair<int, int> &value, int left, int right);
int GetHighestIndexForLowestComparison(int k);

int PmergeMe::comparison_ = 0;
int comp = 0;

// Vector
void PmergeMe::MergeInsertionSortVector(std::vector<int> &vec) {
  std::vector<std::pair<int, int> > chained;
  int lefted = -1;
  if (vec.size() % 2 && vec.size() > 1) {
    lefted = vec.back();
  }
  for (size_t i = 0; i + 1 < vec.size(); i += 2) {
    if (vec[i] > vec[i + 1]) {
      chained.push_back(std::make_pair(vec[i], vec[i + 1]));
    } else {
      chained.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
    PmergeMe::IncreaseComparison();
  }
  
  std::vector<std::pair<int, int> > sorted;
  for (size_t i = 0; i < chained.size(); ++i) {
    BinaryInsertionVector(sorted, chained[i]);
  }

  std::vector<int> sequences;
  for (size_t i = 1; ; ++i) {
    int sequence = GetHighestIndexForLowestComparison(i);
    if (sequence >= sorted.size()) {
      sequences.push_back(sequence);
      break;
    }
    sequences.push_back(sequence);
    if (sequences[i - 1] == sorted.size() - 1) {
      break;
    }
  }

  vec.clear();
  vec.push_back(sorted[0].second);
  for (size_t i = 1; i < sequences.size(); ++i) {
    int index;

    index = sequences[i - 1];
    while (index < sequences[i]) {
      vec.push_back(sorted[index].first);
      index++;
    }
    index = sequences[i];
    if (index >= sorted.size() - 1) {
      if (lefted != -1) {
        BinaryInsertionVector(vec, lefted);
        lefted = -1;
      }
      index = sorted.size() - 1;
    }
    while (index > sequences[i - 1]) {
      BinaryInsertionVector(vec, sorted[index].second);
      index--;
    }
  }
  vec.push_back(sorted[sorted.size() - 1].first);


  if (lefted != -1) {
    BinaryInsertionVector(vec, lefted);
  }
}

static void BinaryInsertionVector(std::vector<std::pair<int, int> > &vec, std::pair<int, int> &value) {
  int left = 0, right = static_cast<int>(vec.size());
  
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    PmergeMe::IncreaseComparison();
    comp++;
    if (vec[mid].first < value.first) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  std::cout << comp << '\n';
  comp = 0;

  vec.insert(vec.begin() + left, value);
}

static void BinaryInsertionVector(std::vector<int> &vec, int value) {
  int left = 0, right = static_cast<int>(vec.size());

  while (left < right) {
    int mid = left + ((right - left) >> 1);
    PmergeMe::IncreaseComparison();
    comp++;
    if (vec[mid] < value) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  std::cout << comp << '\n';
  comp = 0;

  vec.insert(vec.begin() + left, value);
}

// List
// void PmergeMe::MergeInsertionSortList(std::list<int> &lst) {
//   std::list<std::pair<int, int> > chained;
//   int lefted = -1;
//   if (lst.size() % 2 && lst.size() > 1) {
//     lefted = lst.back();
//   }
//   std::list<int>::iterator iter = lst.begin();
//   int n = lst.size() / 2;
//   for (int i = 0; i < n; ++i, ++iter) {
//     int value1 = *iter;
//     int value2 = *(++iter);
//     if (value1 > value2) {
//       chained.push_back(std::make_pair(value1, value2));
//     } else {
//       chained.push_back(std::make_pair(value2, value1));
//     }
//   }
//   std::list<std::pair<int, int> >::iterator itter = chained.begin();
//   MergeSortList(chained, 0, chained.size() - 1);
//   lst.clear();
//   std::list<std::pair<int, int> >::iterator iter_chained = chained.begin();
//   for (size_t i = 0; i < chained.size(); ++i) {
//     BinaryInsertionList(lst, (*iter_chained).second, 0, lst.size() - 1);
//     lst.push_back((*iter_chained).first);
//     iter_chained++;
//   }
//   if (lefted != -1) {
//     BinaryInsertionList(lst, lefted, 0, lst.size() - 1);
//   }
// }

// static void BinaryInsertionList(std::list<int> &lst, std::pair<int, int> &value, int left, int right) {
//   int mid = (left + right) / 2;

//   while (left <= right) {
//     std::list<int>::iterator iter = lst.begin();
//     std::advance(iter, mid);
//     if (*iter < value.first) {
//       left = mid + 1;
//     } else {
//       right = mid - 1;
//     }
//     mid = (left + right) / 2;
//   }
//   std::list<int>::iterator iter = lst.begin();
//   std::advance(iter, left);
//   // lst.insert(iter, value);
// }

void PmergeMe::IncreaseComparison() {
  comparison_++;
}

void PmergeMe::PrintComaprison() {
  std::cout << "comparison: " << comparison_ << "\n";
}

int GetHighestIndexForLowestComparison(int k) {
  if (k == 0) {
    return 0;
  }
  
  int order;
  if (k % 2) {
    order = ((1 << (k + 1)) - 1) / 3;
  } else {
    order = ((1 << (k + 1)) + 1) / 3;
  }

  return order - 1;
}

// clang-format on