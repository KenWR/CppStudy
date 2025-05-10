#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

// clang-format off
static void BinaryInsertionVector(std::vector<std::pair<int, int> > &vec, std::pair<int, int> &value, int left, int right);
static void BinaryInsertionVector(std::vector<int> &vec, int value, int left, int right);
// static void BinaryInsertionList(std::list<int> &lst, std::pair<int, int> &value, int left, int right);
int GetHighestIndexForLowestComparison(int k);

int PmergeMe::comparison_ = 0;

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
    BinaryInsertionVector(sorted, chained[i], 0, sorted.size() - 1);
  }

  // ============= 여기가 수열 사용 ===========
  std::vector<int> sequences;
  for (size_t i = 0; ; ++i) {
    int sequence = GetHighestIndexForLowestComparison(i);
    if (sequence >= sorted.size()) {
      sequence = sorted.size() - 1;
      sequences.push_back(sequence);
      break;
    }
    sequences.push_back(sequence);
  }

  vec.clear();
  for (size_t i = 0; i < sorted.size(); ++i) {
    vec.push_back(sorted[i].first);
  }
  vec.insert(vec.begin(), sorted.front().second);

  int count = 1;
  for (size_t i = 1; i < sequences.size(); ++i) {
    int before = sequences[i - 1];
    int current = sequences[i];
    while (current > before) {
      BinaryInsertionVector(vec, sorted[current].second, 0, (count * 2) - 1);
      current--;
      count++;
    }
    std::cout << "count: " << count *2 - 1<< '\n';
  }
  // ========================================

  if (lefted != -1) {
    BinaryInsertionVector(vec, lefted, 0, vec.size() - 1);
  }
}

static void BinaryInsertionVector(std::vector<std::pair<int, int> > &vec, std::pair<int, int> &value, int left, int right) {
  int mid = (left + right) / 2;

  while (left <= right) {
    if (vec[mid].first <= value.first) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    mid = (left + right) / 2;
    PmergeMe::IncreaseComparison();
  }

  vec.insert(vec.begin() + left, value);
}

static void BinaryInsertionVector(std::vector<int> &vec, int value, int left, int right) {
  int mid = (left + right) / 2;

  while (left <= right) {
    if (vec[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    mid = (left + right) / 2;
    PmergeMe::IncreaseComparison();
  }

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

  return order;
}

// clang-format on