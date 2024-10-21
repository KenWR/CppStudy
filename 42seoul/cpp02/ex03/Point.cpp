#include "Point.hpp"

Point::Point() 
	: x_(0), y_(0), z_(0) {
}

Point::Point(const Fixed& x, const Fixed& y, const Fixed& z) 
	: x_(x), y_(y), z_(z) {
}

Point::Point( const Point& copy )
	: x_(copy.x_), y_(copy.y_), z_(copy.z_) {
}

Point& Point::operator=( const Point& src ) {
	if (this != &src) {
	}
	return (*this);
}

Point Point::operator-( Point const p ) const {
	return (Point(this->getX() - p.getX(), this->getY() - p.getY(), this->getZ() - p.getZ()));
}

Point Point::operator+( Point const p ) const {
	return (Point(this->getX() + p.getX(), this->getY() + p.getY(), this->getZ() + p.getZ()));
}

Point Point::operator*( Point const p ) const {
	return (Point(this->getX() * p.getX(), this->getY() * p.getY(), this->getZ() * p.getZ()));
}

Point Point::operator/( Point const p ) const {
	return (Point(this->getX() / p.getX(), this->getY() / p.getY(), this->getZ() / p.getZ()));
}

Point::~Point() {

}

const Fixed& Point::getX() const {
	return (this->x_);
}

const Fixed& Point::getY() const {
	return (this->y_);
}

const Fixed& Point::getZ() const {
	return (this->z_);
}
