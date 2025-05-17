#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <list>
#include <utility>
#include <vector>

class PmergeMe {
private:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
  static void MergeInsertionSortVector(std::vector<std::pair<int, int> > &vec);
  static void MergeInsertionSortList(std::list<std::pair<int, int> > &lst);

public:
  static void MergeInsertionSortVector(std::vector<int> &vec);
  static void MergeInsertionSortList(std::list<int> &lst);

};

#endif // PmergeMe