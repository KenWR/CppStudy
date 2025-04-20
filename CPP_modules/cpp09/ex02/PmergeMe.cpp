#include "PmergeMe.hpp"

#include <algorithm>
#include <list>
#include <vector>

// public
void PmergeMe::MergeInsertionSortVector(std::vector<int> &vec) {}
void PmergeMe::MergeInsertionSortList(std::list<int> &lst) {}

// private

void MergeSortList(std::list<int> &lst, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (right - left) / 2;
  MergeSortList(lst, left, mid);
  MergeSortList(lst, mid + 1, right);
  MergeList(lst, left, mid, right);
}

void MergeList(std::list<int> &lst, int left, int mid, int right) {}
