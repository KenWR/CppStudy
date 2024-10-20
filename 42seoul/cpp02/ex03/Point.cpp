#include "Point.hpp"

Point::Point() {

}

Point::Point(Fixed& x, Fixed& y, Fixed& z) 
	: x_(x), y_(y), z_(z) {
}

Point::Point( const Point& copy )
	: x_(copy.x_), y_(copy.y_), z_(copy.z_) {
}

Point& Point::operator=( const Point& src ) {
	if (this != &src) {
		this->x_ = src.x_;
		this->y_ = src.y_;
		this->z_ = src.z_;
	}
	return (*this);
}

Point::~Point() {

}

Fixed Point::getX() const {
	return (this->x_);
}

Fixed Point::getY() const {
	return (this->y_);
}

Fixed Point::getZ() const {
	return (this->z_);
}

void Point::setX( Fixed& fp ) {
	this->x_ = fp;
}

void Point::setY( Fixed& fp ) {
	this->y_ = fp;
}

void Point::setZ( Fixed& fp ) {
	this->z_ = fp;
}
