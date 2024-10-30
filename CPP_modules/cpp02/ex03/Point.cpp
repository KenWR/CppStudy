#include "Point.hpp"

Point::Point() 
	: x_(0), y_(0) {
}

Point::Point(const Fixed& x, const Fixed& y) 
	: x_(x), y_(y) {
}

Point::Point( const Point& copy )
	: x_(copy.x_), y_(copy.y_) {
}

Point& Point::operator=( const Point& src ) {
	if (this != &src) {
	}
	return (*this);
}

Point Point::operator-( Point const p ) const {
	return (Point(this->getX() - p.getX(), this->getY() - p.getY()));
}

Point Point::operator+( Point const p ) const {
	return (Point(this->getX() + p.getX(), this->getY() + p.getY()));
}

Point::~Point() {

}

const Fixed& Point::getX() const {
	return (this->x_);
}

const Fixed& Point::getY() const {
	return (this->y_);
}

std::ostream& operator<<( std::ostream& os, const Point& p ) {
	os << "x:" << p.getX() << " ";
	os << "y:" << p.getY();
	return (os);
}
