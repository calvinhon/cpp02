#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class   Point {

public:
    Point();
    Point(const float x0, const float y0);
    Point(const Point& src);
    Point& operator=(const Point& src);
    ~Point();

    Fixed const getX (void) const;
    Fixed const getY (void) const;

private:
    Fixed const _x;
    Fixed const _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif