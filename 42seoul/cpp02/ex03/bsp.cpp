#include "Point.hpp"
#include "Fixed.hpp"

static Fixed dot( const Point& p1, const Point& p2 );
static Point cross( const Point& p1, const Point& p2);

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Point ap(a - point); // using as a vector
	Point bp(b - point);
	Point cp(c - point);

	Point u = cross(bp, cp);
	Point v = cross(cp, ap);
	Point w = cross(ap, bp);
	
	if (dot(u, v) < 0.0f) {
      return false;
	}
	if (dot(u, w) < 0.0f) {
		return false;
	}

	return true;
}


static Point cross( const Point& p1, const Point& p2) {
	return (Point(
		p1.getY() * p2.getZ() - p1.getZ() * p2.getY(), 
		p1.getZ() * p2.getX() - p1.getX() * p2.getZ(), 
		p1.getX() * p2.getY() - p1.getY() * p2.getX()
	));
}

static Fixed dot( const Point& p1, const Point& p2 ) {
	return (p1.getX() * p2.getX() + p1.getY() * p2.getY() + p1.getZ() * p2.getZ());
}
