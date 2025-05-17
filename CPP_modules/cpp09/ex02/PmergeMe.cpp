#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

// clang-format off
static void BinaryInsertionVector(std::vector<std::pair<int, int> > &vec, std::pair<int, int> &value);
static void BinaryInsertionList(std::list<std::pair<int, int> > &lst, std::pair<int, int> &value);
int GetSequence(int k);

// Vector
void PmergeMe::MergeInsertionSortVector(std::vector<int> &vec) {
  std::vector<std::pair<int, int> > chained;
  for (size_t i = 0; i < vec.size(); ++i) {
    chained.push_back(std::make_pair(vec[i], -1));
  }

  PmergeMe::MergeInsertionSortVector(chained);

  vec.clear();
  for (size_t i = 0; i < chained.size(); ++i) {
    vec.push_back(chained[i].first);
  }
}

void PmergeMe::MergeInsertionSortVector(std::vector<std::pair<int, int> > &vec) {
  if (vec.size() <= 1) {
    return;
  }
  if (vec.size() == 2) {
    if (vec[0].first > vec[1].first) {
      std::swap(vec[0], vec[1]);
    }
    return;
  }

  // Step i: Make pairwise comparisons of [n/2] disjoint pairs of elements. 
  // (If n is odd, leave one element out.) 
  std::vector<std::pair<int, int> > sorted_winners;
  std::vector<std::pair<int, int> > winners;
  std::vector<std::pair<int, int> > losers;
  bool lefted = false;

  for (size_t i = 0; i + 1 < vec.size(); i += 2) {
    if (vec[i].first > vec[i + 1].first) {
      sorted_winners.push_back(std::make_pair(vec[i].first, i / 2));
      winners.push_back(vec[i]);
      losers.push_back(vec[i + 1]);
    } else {
      sorted_winners.push_back(std::make_pair(vec[i + 1].first, i / 2));
      winners.push_back(vec[i + 1]);
      losers.push_back(vec[i]);
    }
  }
  if (vec.size() % 2 && vec.size() > 1) {
    lefted = true;
    losers.push_back(vec.back());
  }
  
  // Step ii: Sort the [n/2] larger numbers, found in step (i), by merge insertion. 
  PmergeMe::MergeInsertionSortVector(sorted_winners);

  // Step iii: Insert the remaining b's into the main chain, using binary insertion, 
  // in the following order  (2^(k+l) + (-l)^k) /3 .
  vec.clear();
  if (sorted_winners[0].second != -1) {
    vec.push_back(losers[sorted_winners[0].second]);
  }
  for (size_t i = 1; ; ++i) {
    int current = GetSequence(i);
    int before = GetSequence(i - 1);
    if (current > sorted_winners.size() - 1) {
      current = sorted_winners.size() - 1;
    }
    int index = before;
    while (index < current) {
      if (sorted_winners[index].second != -1) {
        vec.push_back(winners[sorted_winners[index].second]);
      }
      index++;
    }
    index = current;
    while (index > before) {
      if (sorted_winners[index].second != -1) {
        BinaryInsertionVector(vec, losers[sorted_winners[index].second]);
      }
      index--;
    }
    if (current >= sorted_winners.size() - 1) {
      break;
    }
  }
  if (sorted_winners.back().second != -1) {
    vec.push_back(winners[sorted_winners.back().second]);
  }
  if (lefted == true) {
    BinaryInsertionVector(vec, losers.back());
  }
}

static void BinaryInsertionVector(std::vector<std::pair<int, int> > &vec, std::pair<int, int> &value) {
  int left  = 0;
  int right = static_cast<int>(vec.size()) - 1;
  
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (value.first < vec[mid].first) {
        right = mid - 1;
    } else {
        left = mid + 1;
    }
  }

  vec.insert(vec.begin() + left, value);
}

void PmergeMe::MergeInsertionSortList(std::list<int> &lst) {
  std::list<std::pair<int, int> > chaind;
  for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    chaind.push_back(std::make_pair(*it, -1));
  }

  MergeInsertionSortList(chaind);

  lst.clear();
  for (std::list<std::pair<int, int> >::iterator it = chaind.begin(); it != chaind.end(); ++it) {
    lst.push_back((*it).first);
  }
}

void PmergeMe::MergeInsertionSortList(std::list<std::pair<int, int> >& lst) {
  if (lst.size() <= 1) {
    return;
  }
  if (lst.size() == 2) {
    std::list<std::pair<int, int> >::iterator a = lst.begin();
    std::list<std::pair<int, int> >::iterator b = a; 
    ++b;
    if (a->first > b->first) {
        std::pair<int, int> tmp = *a; 
        *a = *b; 
        *b = tmp;
    }
    return;
  }

  // Step i: Make pairwise comparisons of [n/2] disjoint pairs of elements. 
  // (If n is odd, leave one element out.) 
  std::list<std::pair<int, int> > sorted_winners;
  std::list<std::pair<int, int> > winners;
  std::list<std::pair<int, int> > losers;
  bool lefted = false;
  

  int idx = 0;
  std::list<std::pair<int, int> >::iterator it1 = lst.begin();
  std::list<std::pair<int, int> >::iterator it2 = it1;
  it2++;
  while (it1 != lst.end() && it2 != lst.end()) {
    if (it1->first > it2->first) {
        sorted_winners.push_back(std::make_pair(it1->first, idx));
        winners.push_back(*it1);
        losers.push_back(*it2);
    } else {
        sorted_winners.push_back(std::make_pair(it2->first, idx));
        winners.push_back(*it2);
        losers.push_back(*it1);
    }
    ++idx;
    ++it1;
    ++it1;
    ++it2;
    ++it2;
  }
  if (lst.size() % 2 == 1) {
    lefted = true;
    losers.push_back(lst.back());
  }

  // Step ii: Sort the [n/2] larger numbers, found in step (i), by merge insertion.
  MergeInsertionSortList(sorted_winners);

  // Step iii: Insert the remaining b's into the main chain, using binary insertion, 
  // in the following order  (2^(k+l) + (-l)^k) /3 .
  lst.clear();
  if (sorted_winners.front().second != -1) {
    std::list<std::pair<int, int> >::iterator temp = losers.begin();
    std::advance(temp, sorted_winners.front().second);
    lst.push_back(*temp);
  }
  for (size_t i = 1; ; ++i) {
    int current = GetSequence(i);
    int before = GetSequence(i - 1);
    if (current > sorted_winners.size() - 1) {
      current = sorted_winners.size() - 1;
    }
    int index = before;
    std::list<std::pair<int, int> >::iterator sorted_winner;
    while (index < current) {
      std::list<std::pair<int, int> >::iterator sorted_winner = sorted_winners.begin();
      std::advance(sorted_winner, index);
      if ((*sorted_winner).second != -1) {
        std::list<std::pair<int, int> >::iterator winner = winners.begin();
        std::advance(winner, (*sorted_winner).second);
        lst.push_back(*winner);
        index++;
      }
    }

    index = current;
    while (index > before) {
      std::list<std::pair<int, int> >::iterator sorted_winner = sorted_winners.begin();
      std::advance(sorted_winner, index);
      if ((*sorted_winner).second != -1) {
        std::list<std::pair<int, int> >::iterator loser = losers.begin();
        std::advance(loser, (*sorted_winner).second);
        BinaryInsertionList(lst, *loser);
        index--;
      }
    }

    if (current >= sorted_winners.size() -1) {
      break;
    }
  }
  if (sorted_winners.back().second != -1) {
    std::list<std::pair<int, int> >::iterator sorted_winner = sorted_winners.end();
    sorted_winner--;
    std::list<std::pair<int, int> >::iterator winner = winners.begin();
    std::advance(winner, (*sorted_winner).second);
    lst.push_back(*winner);
  }
  if (lefted == true) {
    BinaryInsertionList(lst, losers.back());
  }
}

static void BinaryInsertionList(std::list<std::pair<int, int> > &lst, std::pair<int, int> &value) {
  if (lst.empty()) {
    lst.push_front(value);
    return;
  }

  int left  = 0;
  int right = static_cast<int>(lst.size()) - 1;
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    std::list<std::pair<int,int> >::iterator midIt = lst.begin();
    std::advance(midIt, mid);

    if (value.first < midIt->first) {
        right = mid - 1;
    } else {
        left = mid + 1;
    }
  }

  std::list<std::pair<int, int> >::iterator iter = lst.begin();
  std::advance(iter, left);
  lst.insert(iter, value);
}

int GetSequence(int k) {
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