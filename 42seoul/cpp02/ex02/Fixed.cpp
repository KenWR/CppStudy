#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

const int Fixed::fractional_bits = 8;

// orthodox canonical form

/**
 * @brief initialized the fixed-point number value to 0
*/
Fixed::Fixed() : fixed_point_number_( 0 ) {
}

Fixed::Fixed( const int integer_number ) 
	: fixed_point_number_( integer_number * BITS_MOVE ) {
}

Fixed::Fixed( const float float_pointer_number )
	: fixed_point_number_( std::roundf(float_pointer_number * BITS_MOVE) ) {
}

Fixed::Fixed( const Fixed& copy ) {
	this->fixed_point_number_ = copy.fixed_point_number_;
}

Fixed& Fixed::operator=( const Fixed& src ) {
	if (this != &src) {
		this->fixed_point_number_ = src.fixed_point_number_;
	}
	return (*this);
}

Fixed::~Fixed() {
}


// member functions

int	Fixed::getRawBits( void ) const {
	return (this->fixed_point_number_);	
}

void	Fixed::setRawBits( int const raw ) {
	this->fixed_point_number_ = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(this->fixed_point_number_) / static_cast<float>(BITS_MOVE);
}

int	Fixed::toInt( void ) const {
	return this->fixed_point_number_ / BITS_MOVE;
}

// Comparison
bool Fixed::operator>(const Fixed& src) const {
	return this->getRawBits() > src.getRawBits();
}

bool Fixed::operator<(const Fixed& src) const {
	return this->getRawBits() < src.getRawBits();
}

bool Fixed::operator>=(const Fixed& src) const {
	return this->getRawBits() >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed& src) const {
	return this->getRawBits() <= src.getRawBits();
}

bool Fixed::operator==(const Fixed& src) const {
	return this->getRawBits() == src.getRawBits();
}

bool Fixed::operator!=(const Fixed& src) const {
	return this->getRawBits() != src.getRawBits();
}

// Arithmetic
int Fixed::operator+(const Fixed& src) const {
	return this->getRawBits() + src.getRawBits();
}

int Fixed::operator-(const Fixed& src) const {
	return this->getRawBits() - src.getRawBits();
}

int Fixed::operator*(const Fixed& src) const {
	return this->getRawBits() * src.getRawBits();
}

int Fixed::operator/(const Fixed& src) const {
	return this->getRawBits() / src.getRawBits();
}

// Increment and decrement
Fixed& Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed& Fixed::operator++(int) {
	Fixed old = *this;
	operator++();
	return old;
}

Fixed& Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
}

Fixed& Fixed::operator--(int) {
	Fixed old = *this;
	operator--();
	return old;
}


// Min and Max
static Fixed& min(Fixed& fp1, Fixed& fp2) {
	return (fp1 < fp2) ? fp1 : fp2;
}

static const Fixed& min(const Fixed& fp1, const Fixed& fp2) {
	return (fp1 < fp2) ? fp1 : fp2;
}

static Fixed& max(Fixed& fp1, Fixed& fp2) {
	return (fp1 > fp2) ? fp1 : fp2;
}

static const Fixed& max(const Fixed& fp1, const Fixed& fp2) {
	return (fp1 > fp2) ? fp1 : fp2;
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj ) {
	os << obj.toFloat();
	return os;
}


