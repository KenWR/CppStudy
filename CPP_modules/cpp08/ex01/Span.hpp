#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>

class Span {
private:
  std::vector<int> numbers_;
  unsigned int max_size_;

  Span &operator=(Span const &other);
  Span(Span const &other);

public:
  Span(unsigned int n);
  ~Span();

  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;

  class NoSpaceException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "No space left to add a new number";
    }
  };

  class NotEnoughNumbersException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Not enough numbers to calculate the span";
    }
  };
};

#endif // SPAN_HPP