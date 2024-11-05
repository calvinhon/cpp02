#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x0, const float y0): _x(x0), _y(y0) {}

Point::Point(const Point& src): _x(src._x), _y(src._y) {}

Point& Point::operator=(const Point& src) {
    if (this != &src)
        return *this;
    return *this;
}

Point::~Point() {}

Fixed const Point::getX (void) const {
    return _x;
}

Fixed const Point::getY (void) const {
    return _y;
}

