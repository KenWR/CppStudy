#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#include <ostream>

class Point {
private:
	const Fixed x_;
	const Fixed y_;

public:
	
	Point();
	Point(const Fixed& x, const Fixed& y);
	Point( const Point& copy );
	Point& operator=( const Point& src );
	~Point();

	Point operator-( Point const p) const;
	Point operator+( Point const p ) const;

	const Fixed& getX() const;
	const Fixed& getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream& operator<<( std::ostream& os, const Point& p );

#endif