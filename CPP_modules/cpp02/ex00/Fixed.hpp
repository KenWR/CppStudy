#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
  int fixed_point_number_;
  static const int fractional_bits = 8;

public:
  // orthodox canonical form
  Fixed();                            // default constructor
  Fixed(const Fixed &src);            // copy constructor
  Fixed &operator=(const Fixed &src); // copy assignment operator overload
  ~Fixed();                           // DESTRUCTOR

  // member functions
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif