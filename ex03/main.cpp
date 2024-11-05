#include "Fixed.hpp"
#include "Point.hpp"

int	main(void) {
	Point   a(0, 0);
    Point   b(1, 1);
    Point   c(1, 0);
    Point   point(0.3, 0.1);

    std::cout << "Triangle vertices: ";
    std::cout << "a(" << a.getX() << "," << a.getY() << ") ";
    std::cout << "b(" << b.getX() << "," << b.getY() << ") ";
    std::cout << "c(" << c.getX() << "," << c.getY() << ") " << std::endl;
    
    std::cout << "Point coordinates: ";
    std::cout << "p(" << point.getX() << "," << point.getY() << ") " << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "Point is in the triangle!!!" << std::endl;
    else
        std::cout << "Point is NOT in the triangle!!!" << std::endl;

    return 0;
}