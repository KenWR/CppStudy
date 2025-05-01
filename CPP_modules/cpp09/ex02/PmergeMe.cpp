#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

// clang-format off
static void BinaryInsertionVector(std::vector<int> &vec, int value);
static void BinaryInsertionList(std::list<int> &lst, int value);
static void MergeSortVector(std::vector<std::pair<int, int> > &vec, int left,
                            int right);
static void MergeSortList(std::list<std::pair<int, int> > &lst, int left,
                          int right);
static void MergeVector(std::vector<std::pair<int, int> > &vec, int left,
                        int mid, int right);
static void MergeList(std::list<std::pair<int, int> > &lst, int left, int mid,
                      int right);

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
      PmergeMe::IncreaseComparison();
    } else {
      chained.push_back(std::make_pair(vec[i + 1], vec[i]));
      PmergeMe::IncreaseComparison();
    }
  }
  MergeSortVector(chained, 0, chained.size() - 1);
  vec.clear();
  for (size_t i = 0; i < chained.size(); ++i) {
    BinaryInsertionVector(vec, chained[i].second);
    vec.push_back(chained[i].first);
  }
  if (lefted != -1) {
    BinaryInsertionVector(vec, lefted);
  }
}

static void MergeSortVector(std::vector<std::pair<int, int> > &vec, int left,
                            int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  MergeSortVector(vec, left, mid);
  MergeSortVector(vec, mid + 1, right);
  MergeVector(vec, left, mid, right);
}

static void MergeVector(std::vector<std::pair<int, int> > &vec, int left,
                        int mid, int right) {
  std::vector<std::pair<int, int> > vec_temp;

  int index_left = left;
  int index_right = mid + 1;
  while (index_left <= mid && index_right <= right) {
    if (vec[index_left].first < vec[index_right].first) {
      vec_temp.push_back(vec[index_left++]);
    } else {
      vec_temp.push_back(vec[index_right++]);
    }
    PmergeMe::IncreaseComparison();
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

static void BinaryInsertionVector(std::vector<int> &vec, int value) {
  int left = 0;
  int right = vec.size() - 1;
  int mid = (left + right) / 2;

  while (left <= right) {
    if (vec[mid] <= value) {
      left = mid + 1;
      PmergeMe::IncreaseComparison();
    } else {
      right = mid - 1;
      PmergeMe::IncreaseComparison();
    }
    mid = (left + right) / 2;
  }
  vec.insert(vec.begin() + left, value);
}

int getOrderForLowestComparison() {
  
}

// List
void PmergeMe::MergeInsertionSortList(std::list<int> &lst) {
  std::list<std::pair<int, int> > chained;
  int lefted = -1;
  if (lst.size() % 2 && lst.size() > 1) {
    lefted = lst.back();
  }
  std::list<int>::iterator iter = lst.begin();
  int n = lst.size() / 2;
  for (int i = 0; i < n; ++i, ++iter) {
    int value1 = *iter;
    int value2 = *(++iter);
    if (value1 > value2) {
      chained.push_back(std::make_pair(value1, value2));
    } else {
      chained.push_back(std::make_pair(value2, value1));
    }
  }
  std::list<std::pair<int, int> >::iterator itter = chained.begin();
  MergeSortList(chained, 0, chained.size() - 1);
  lst.clear();
  std::list<std::pair<int, int> >::iterator iter_chained = chained.begin();
  for (size_t i = 0; i < chained.size(); ++i) {
    BinaryInsertionList(lst, (*iter_chained).second);
    lst.push_back((*iter_chained).first);
    iter_chained++;
  }
  if (lefted != -1) {
    BinaryInsertionList(lst, lefted);
  }
}

static void MergeSortList(std::list<std::pair<int, int> > &lst, int left,
                          int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  MergeSortList(lst, left, mid);
  MergeSortList(lst, mid + 1, right);
  MergeList(lst, left, mid, right);
}

static void MergeList(std::list<std::pair<int, int> > &lst, int left, int mid,
                      int right) {
  std::list<std::pair<int, int> > lst_temp;

  std::list<std::pair<int, int> >::iterator iter_left = lst.begin();
  std::list<std::pair<int, int> >::iterator iter_right = lst.begin();
  std::advance(iter_left, left);
  std::advance(iter_right, mid + 1);
  std::list<std::pair<int, int> >::iterator iter = iter_left;

  int left_index = left, right_index = mid + 1;
  while (left_index <= mid && right_index <= right) {
    if (*iter_left < *iter_right) {
      lst_temp.push_back(*iter_left);
      iter_left++;
      left_index++;
    } else {
      lst_temp.push_back(*iter_right);
      iter_right++;
      right_index++;
    }
  }

  while (left_index <= mid) {
    lst_temp.push_back(*iter_left);
    iter_left++;
    left_index++;
  }
  while (right_index <= right) {
    lst_temp.push_back(*iter_right);
    iter_right++;
    right_index++;
  }

  std::list<std::pair<int, int> >::iterator iter_temp = lst_temp.begin();
  for (size_t i = 0; i < lst_temp.size(); ++i) {
    (*iter) = *iter_temp;
    iter++;
    iter_temp++;
  }
}

static void BinaryInsertionList(std::list<int> &lst, int value) {
  int left = 0;
  int right = lst.size() - 1;
  int mid = (left + right) / 2;

  while (left <= right) {
    std::list<int>::iterator iter = lst.begin();
    std::advance(iter, mid);
    if (*iter < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    mid = (left + right) / 2;
  }
  std::list<int>::iterator iter = lst.begin();
  std::advance(iter, left);
  lst.insert(iter, value);
}

void PmergeMe::IncreaseComparison() {
  comparison_++;
}

void PmergeMe::PrintComaprison() {
  std::cout << "comparison: " << comparison_ << "\n";
}

// clang-format on