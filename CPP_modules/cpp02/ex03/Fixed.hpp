#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

#define BITS_MOVE (1 << fractional_bits_)

class Fixed {
private:
  int fixed_point_number_;
  static const int fractional_bits_;

public:
  // orthodox canonical form
  Fixed(); // default constructor
  Fixed(const int integer_number);
  Fixed(const float floating_point_number);
  Fixed(const Fixed &src);            // copy constructor
  Fixed &operator=(const Fixed &src); // copy assignment operator overload
  ~Fixed();                           // DESTRUCTOR

  // member functions
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  // Comparison
  bool operator>(const Fixed &l) const;
  bool operator<(const Fixed &l) const;
  bool operator>=(const Fixed &l) const;
  bool operator<=(const Fixed &l) const;
  bool operator==(const Fixed &l) const;
  bool operator!=(const Fixed &l) const;

  // Arithmetic
  Fixed operator+(const Fixed &src) const;
  Fixed operator-(const Fixed &src) const;
  Fixed operator*(const Fixed &src) const;
  Fixed operator/(const Fixed &src) const;

  // Increment and decrement
  Fixed &operator++();   // prefix increment
  Fixed operator++(int); // postfix increment
  Fixed &operator--();   // prefix decrement
  Fixed operator--(int); // postfix decrement

  // Min and Max
  static Fixed &min(Fixed &fp1, Fixed &fp2);
  static const Fixed &min(const Fixed &fp1, const Fixed &fp2);
  static Fixed &max(Fixed &fp1, Fixed &fp2);
  static const Fixed &max(const Fixed &fp1, const Fixed &fp2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif