#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <list>
#include <utility>
#include <vector>

class PmergeMe {
private:
  static int comparison_;

  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);

public:
  static void IncreaseComparison();
  static void PrintComaprison();
  static void MergeInsertionSortVector(std::vector<int> &vec);
  static void MergeInsertionSortList(std::list<int> &lst);
};

#endif // PmergeMe