#include "PmergeMe.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include <sys/time.h>

struct ElapsedTime {
  long seconds;
  long milliseconds;
  long microseconds;
};

bool IsPositiveSequence(const std::vector<int> &vec);
void PrintContainer(const std::vector<int> &vec);
void PrintContainer(const std::list<int> &lst);
ElapsedTime GetTimeBreakdown(timeval &start, timeval &end);

int main(int argc, char **argv) {
  std::vector<int> vec;
  std::list<int> lst;
  timeval start, end;
  ElapsedTime elapsed;

  for (int i = 1; i < argc; ++i) {
    for (int j = 0; argv[i][j] != '\0'; ++j) {
      if (isdigit(argv[i][j]) == false) {
        std::cerr << "This is not number\n";
        return 1;
      }
    }
    int number = atoi(argv[i]);
    vec.push_back(number);
    lst.push_back(number);
  }

  if (IsPositiveSequence(vec) == false) {
    std::cerr << "Input numbers are not positive integer sequence\n";
    return 1;
  } else if (vec.size() <= 1) {
    std::cerr << "There is no enough numbers to sort\n";
    return 1;
  } else if (vec.size() > 3000) {
    std::cerr << "Not allowed to over 3000 numbers\n";
    return 1;
  }

  std::cout << "============== vector ==============\n";
  std::cout << "before: ";
  PrintContainer(vec);
  gettimeofday(&start, NULL);
  PmergeMe::MergeInsertionSortVector(vec);
  gettimeofday(&end, NULL);
  std::cout << "after:  "; 
  PrintContainer(vec);

  elapsed = GetTimeBreakdown(start, end);
  std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
            << elapsed.seconds << " s "
            << elapsed.milliseconds << " ms "
            << elapsed.microseconds << " us\n";
  std::cout << "====================================\n\n";

  std::cout << "================ list ==============\n";
  std::cout << "before: ";
  PrintContainer(lst);
  gettimeofday(&start, NULL);
  PmergeMe::MergeInsertionSortList(lst);
  gettimeofday(&end, NULL);
  std::cout << "after: ";
  PrintContainer(lst);

  elapsed = GetTimeBreakdown(start, end);
  std::cout << "Time to process a range of " << vec.size() << " elements with std::list: "
            << elapsed.seconds << " s " 
            << elapsed.milliseconds << " ms "
            << elapsed.microseconds << " us\n";
  std::cout << "====================================\n";
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

ElapsedTime GetTimeBreakdown(timeval &start, timeval &end) {
  long sec = end.tv_sec - start.tv_sec;
  long usec = end.tv_usec - start.tv_usec;

  if (usec < 0) {
      sec -= 1;
      usec += 1000000;
  }

  ElapsedTime result;
  result.seconds = sec;
  result.milliseconds = usec / 1000;             // 1 ms = 1000 us
  result.microseconds = usec % 1000;             // 나머지 μs

  return result;
}