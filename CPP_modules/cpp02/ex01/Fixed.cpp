#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

const int Fixed::fractional_bits = 8;

// orthodox canonical form

/**
 * @brief initialized the fixed-point number value to 0
 */
Fixed::Fixed() : fixed_point_number_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer_number)
    : fixed_point_number_(integer_number * BITS_MOVE) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_pointer_number)
    : fixed_point_number_(roundf(float_pointer_number * BITS_MOVE)) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;

  this->fixed_point_number_ = copy.fixed_point_number_;
}

Fixed &Fixed::operator=(const Fixed &src) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this != &src) {
    this->fixed_point_number_ = src.fixed_point_number_;
  }
  return (*this);
}

Fixed::~Fixed() { std::cout << "DESTRUCTOR called" << std::endl; }

// member functions

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;

  return (this->fixed_point_number_);
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;

  this->fixed_point_number_ = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->fixed_point_number_) /
         static_cast<float>(BITS_MOVE);
}

int Fixed::toInt(void) const { return this->fixed_point_number_ / BITS_MOVE; }

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  os << obj.toFloat();
  return os;
}
