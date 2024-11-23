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
		
		~Fixed();								// DESTRUCTOR

		// member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& obj );

#endif