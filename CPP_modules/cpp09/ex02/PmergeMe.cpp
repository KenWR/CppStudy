#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

// clang-format off
static void BinaryInsertionVector(std::vector<int> &vec, int value);
static void MergeSortVector(std::vector<std::pair<int, int> > &vec, int left,
                     int right);
static void MergeSortList(std::list<std::pair<int, int> > &lst, int left, int right);
static void MergeVector(std::vector<std::pair<int, int> > &vec, int left, int mid,
                 int right);
static void MergeList(std::list<std::pair<int, int> > &lst, int left, int mid,
               int right);

// public
void PmergeMe::MergeInsertionSortVector(std::vector<int> &vec) {
  std::vector<std::pair<int, int> > chained;
  for (size_t i = 0; i + 1 < vec.size(); i += 2) {
    if (vec[i] > vec[i + 1]) {
      chained.push_back(std::make_pair(vec[i], vec[i + 1]));
    } else {
      chained.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
  }
  MergeSortVector(chained, 0, chained.size() - 1);

  std::vector<int> main_chain;
  for (size_t i = 0; i < chained.size(); ++i) {
    main_chain.push_back(chained[i].first);
    BinaryInsertionVector(main_chain, chained[i].second);
    std::cout << chained[i].first << " : " << chained[i].second << "\n";
  }
  if (vec.size() % 2) {
    BinaryInsertionVector(main_chain, vec.back());
  }

  for (size_t i = 0; i < vec.size(); ++i) {
    vec[i] = main_chain[i];
  }
}
void PmergeMe::MergeInsertionSortList(std::list<int> &lst) {}


// static functions
static void BinaryInsertionVector(std::vector<int> &vec, int value) {
  int left = 0;
  int right = vec.size() - 1;
  int mid = (left + right) / 2;

  while (left <= right) {
    if (vec[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    mid = (left + right) / 2;
  }
  vec.insert(vec.begin() + left, value);
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

static void MergeSortList(std::list<std::pair<int, int> > &lst, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  MergeSortList(lst, left, mid);
  MergeSortList(lst, mid + 1, right);
  MergeList(lst, left, mid, right);
}

static void MergeVector(std::vector<std::pair<int, int> > &vec, int left, int mid,
                 int right) {
  std::vector<std::pair<int, int> > vec_temp;

  int index_left = left;
  int index_right = mid + 1;
  while (index_left <= mid && index_right <= right) {
    if (vec[index_left].first < vec[index_right].first) {
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

static void MergeList(std::list<std::pair<int, int> > &lst, int left, int mid,
               int right) {
  std::list<int> lst_temp;

  std::list<std::pair<int, int> >::iterator iter_left = lst.begin();
  std::list<std::pair<int, int> >::iterator iter_right = lst.begin();
  std::advance(iter_left, left);.
  std::advance(iter_right, mid + 1);
  std::list<std::pair<int, int> >::iterator iter = iter_left;

  int left_index = left, right_index = mid + 1;
  while (left_index <= mid && right_index <= right) {
    if (*iter_left < *iter_right) {
      lst_temp.push_back((*iter_left).first);
      iter_left++;
      left_index++;
    } else {
      lst_temp.push_back((*iter_right).first);
      iter_right++;
      right_index++;
    }
  }

  while (left_index <= mid) {
    lst_temp.push_back((*iter_left).first);
    iter_left++;
    left_index++;
  }
  while (right_index <= right) {
    lst_temp.push_back((*iter_right).first);
    iter_right++;
    right_index++;
  }

  std::list<int>::iterator iter_temp = lst_temp.begin();
  for (size_t i = 0; i < lst_temp.size(); ++i) {
    (*iter).first = *iter_temp;
    iter++;
    iter_temp++;
  }
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
// clang-format on