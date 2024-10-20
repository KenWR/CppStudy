#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed x_;
	Fixed y_;
	Fixed z_;

public:
	Point();
	Point::Point(Fixed& x, Fixed& y, Fixed& z);
	Point( const Point& copy );
	Point& operator=( const Point& src );
	~Point();

	Fixed getX() const;
	Fixed getY() const;
	Fixed getZ() const;
	void setX( Fixed& fp );
	void setY( Fixed& fp );
	void setZ( Fixed& fp );
};

#endif