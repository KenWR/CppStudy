#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <vector>

Span::Span(unsigned int n) : max_size_(n) {}

Span::~Span() {}

void Span::addNumber(int number) {
  if (numbers_.size() >= max_size_) {
    throw Span::NoSpaceException();
  }

  numbers_.push_back(number);
}

int Span::shortestSpan() const {
  if (numbers_.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }

  std::vector<int> sorted_numbers = numbers_;
  std::sort(sorted_numbers.begin(), sorted_numbers.end());

  int shortest_span = INT_MAX;
  for (size_t i = 1; i < sorted_numbers.size(); i++) {
    int span = sorted_numbers[i] - sorted_numbers[i - 1];
    if (span < shortest_span) {
      shortest_span = span;
    }
  }

  return shortest_span;
}

int Span::longestSpan() const {
  if (numbers_.size() < 2) {
    throw Span::NotEnoughNumbersException();
  }

  int min_num = INT_MAX;
  int max_num = INT_MIN;

  for (size_t i = 0; i < numbers_.size(); i++) {
    if (numbers_[i] < min_num) {
      min_num = numbers_[i];
    }
    if (numbers_[i] > max_num) {
      max_num = numbers_[i];
    }
  }

  return max_num - min_num;
}
