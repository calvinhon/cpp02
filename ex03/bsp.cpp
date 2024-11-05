#include "Point.hpp"

float   triangle_area(Point const a, Point const b, Point const c) {
    float   A = 0.5
        * (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
        + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
        + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
    if (A < 0)
        return -A;
    return A;
}

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    float A = triangle_area(a, b, c);
    float A1 = triangle_area(a, b, point);
    float A2 = triangle_area(b, c, point);
    float A3 = triangle_area(a, c, point);

    // std::cout << "A: " << A << std::endl;
    // std::cout << "A1: " << A1 << std::endl;
    // std::cout << "A2: " << A2 << std::endl;
    // std::cout << "A3: " << A3 << std::endl;
    return (A1 + A2 + A3 == A) && A1 && A2 && A3;
}