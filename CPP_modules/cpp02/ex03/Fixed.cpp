#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

const int Fixed::fractional_bits_ = 8;

// orthodox canonical form

/**
 * @brief initialized the fixed-point number value to 0
 */
Fixed::Fixed() : fixed_point_number_(0) {}

Fixed::Fixed(const int integer_number)
    : fixed_point_number_(integer_number * BITS_MOVE) {}

Fixed::Fixed(const float float_pointer_number)
    : fixed_point_number_(roundf(float_pointer_number * BITS_MOVE)) {}

Fixed::Fixed(const Fixed &copy) {
  this->fixed_point_number_ = copy.fixed_point_number_;
}

Fixed &Fixed::operator=(const Fixed &src) {
  if (this != &src) {
    this->fixed_point_number_ = src.fixed_point_number_;
  }
  return (*this);
}

Fixed::~Fixed() {}

// member functions

int Fixed::getRawBits(void) const { return (this->fixed_point_number_); }

void Fixed::setRawBits(int const raw) { this->fixed_point_number_ = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->getRawBits()) / static_cast<float>(BITS_MOVE);
}

int Fixed::toInt(void) const { return this->getRawBits() / BITS_MOVE; }

// Comparison
bool Fixed::operator>(const Fixed &src) const {
  return this->getRawBits() > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const {
  return this->getRawBits() < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const {
  return this->getRawBits() >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const {
  return this->getRawBits() <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const {
  return this->getRawBits() == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const {
  return this->getRawBits() != src.getRawBits();
}

// Arithmetic
Fixed Fixed::operator+(const Fixed &src) const {
  return static_cast<float>(this->getRawBits() + src.getRawBits()) / BITS_MOVE;
}

Fixed Fixed::operator-(const Fixed &src) const {
  return static_cast<float>(this->getRawBits() - src.getRawBits()) / BITS_MOVE;
}

Fixed Fixed::operator*(const Fixed &src) const {
  return this->toFloat() * src.toFloat();
}

Fixed Fixed::operator/(const Fixed &src) const {
  return this->toFloat() / src.toFloat();
}

// Increment and decrement
Fixed &Fixed::operator++() {
  this->setRawBits(this->getRawBits() + 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old = *this;
  operator++();
  return old;
}

Fixed &Fixed::operator--() {
  this->setRawBits(this->getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old = *this;
  operator--();
  return old;
}

// Min and Max
Fixed &Fixed::min(Fixed &fp1, Fixed &fp2) {
  if (fp1 < fp2)
    return fp1;
  return fp2;
}

const Fixed &Fixed::min(const Fixed &fp1, const Fixed &fp2) {
  if (fp1 < fp2)
    return fp1;
  return fp2;
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2) {
  if (fp1 > fp2)
    return fp1;
  return fp2;
}

const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2) {
  if (fp1 > fp2)
    return fp1;
  return fp2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  os << obj.toFloat();
  return os;
}
