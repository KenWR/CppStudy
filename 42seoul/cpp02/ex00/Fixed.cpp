#include "Fixed.hpp"
#include <iostream>

// orthodox canonical form

/**
 * @brief initialized the fixed-point number value to 0
*/
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;

	fixed_point_number_ = 0;
}

Fixed::Fixed( const Fixed& copy ) {
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
}

Fixed& Fixed::operator = ( const Fixed& src ) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src) {
		this->fixed_point_number_ = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// member functions

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;

	return (this->fixed_point_number_);	
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;

	this->fixed_point_number_ = raw;
}



