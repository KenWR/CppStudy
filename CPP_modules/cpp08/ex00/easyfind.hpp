#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <cstddef>

namespace ft {

template <typename T>
typename T::iterator easyfind(T &container, const int target) {
  typename T::iterator iter = container.begin();
  for (; iter != container.end(); ++iter) {
    if (*iter == target) {
      return iter;
    }
  }

  return container.end();
}

template <typename T>
typename T::const_iterator easyfind(const T &container, const int target) {
  typename T::const_iterator iter = container.begin();
  for (; iter != container.end(); ++iter) {
    if (*iter == target) {
      return iter;
    }
  }
  
  return container.end();
}

} // namespace ft

#endif