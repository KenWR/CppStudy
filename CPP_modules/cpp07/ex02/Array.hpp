#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
private:
  T *data_;
  size_t size_;

public:
  Array();
  Array(unsigned int n);
  ~Array();
  Array(const Array &other);
  Array &operator=(const Array &other);

  T &operator[](const size_t index);
  const T &operator[](const size_t index) const;

  size_t size() const;
};

template <typename T>
Array<T>::Array() {
  data_ = NULL;
  size_ = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
  data_ = NULL;
  size_ = static_cast<size_t>(n);

  if (n) {
    data_ = new T[size_]();
  }
}

template <typename T>
Array<T>::~Array() {
  delete[] data_;
}

template <typename T>
Array<T>::Array(const Array &other) {
  data_ = NULL;
  size_ = other.size();

  if (size_) {
    data_ = new T[size_]();
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other[i];
    }
  }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
  delete[] data_;
  data_ = NULL;
  size_ = other.size();

  if (size_) {
    data_ = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other[i];
    }
  }

  return *this;
}

template <typename T>
T &Array<T>::operator[](const size_t index) {
  if (index >= size_) {
    throw std::exception();
  }

  return data_[index];
}

template <typename T>
const T &Array<T>::operator[](const size_t index) const {
  if (index >= size_) {
    throw std::exception();
  }

  return data_[index];
}

template <typename T>
size_t Array<T>::size() const {
  return size_;
}

#endif