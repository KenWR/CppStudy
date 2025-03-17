#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  MutantStack();
  MutantStack(MutantStack const &other);
  MutantStack &operator=(MutantStack const &other);
  ~MutantStack();

  // Member functions
  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();

  const_iterator begin() const;
  const_iterator end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP