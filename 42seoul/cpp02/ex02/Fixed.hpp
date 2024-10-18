#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

#define BITS_MOVE (1 << fractional_bits)

class Fixed {
private:
	int	fixed_point_number_;
	static const int fractional_bits;
	
public:
	// orthodox canonical form
	Fixed();								// default constructor
	Fixed( const int integer_number );
	Fixed( const float floating_point_number );
	Fixed( const Fixed& src );				// copy constructor
	Fixed& operator=( const Fixed& src );	// copy assignment operator overload
	~Fixed();								// destructor

	// member functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// Comparison
	bool operator>(const Fixed& l, const Fixed& r);
	bool operator<(const Fixed& l, const Fixed& r);
	bool operator>=(const Fixed& l, const Fixed& r);
	bool operator<=(const Fixed& l, const Fixed& r);
	bool operator==(const Fixed& l, const Fixed& r);
	bool operator!=(const Fixed& l, const Fixed& r);

	// Arithmetic
	operator int(void);
	int operator+(const Fixed& src);
	int operator-(const Fixed& src);
	int operator*(const Fixed& src);
	int operator/(const Fixed& src);

	// Increment and decrement
	Fixed& operator++();	// prefix increment
	Fixed& operator++(int);	// postfix increment
	Fixed& operator--();	// prefix decrement
	Fixed& operator--(int);	// postfix decrement

	// Min and Max
	static int& min(int& fp1, int& fp2);
	static int& min(const int& fp1, const int& fp2);
	static int& max(int& fp1, int& fp2);
	static int& max(const int& fp1, const int& fp2);
};

std::ostream& operator<<( std::ostream& os, const Fixed& obj );

#endif