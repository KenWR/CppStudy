#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	const Fixed x_;
	const Fixed y_;
	const Fixed z_;

public:
	
	Point();
	Point(const Fixed& x, const Fixed& y, const Fixed& z);
	Point( const Point& copy );
	Point& operator=( const Point& src );
	~Point();

	Point operator-( Point const p) const;
	Point operator+( Point const p ) const;
	Point operator*( Point const p ) const;
	Point operator/( Point const p ) const;

	const Fixed& getX() const;
	const Fixed& getY() const;
	const Fixed& getZ() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif