#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(-1);
	Fixed const z;

    std::cout << "========== Variable Value ==========" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "z: " << z << std::endl;
    std::cout << std::endl;

    std::cout << "========== Comparison Operators ==========" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a >= z: " << (a >= z) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == z: " << (a == z) << std::endl;
    std::cout << "a != z: " << (a != z) << std::endl;
    std::cout << std::endl;

    std::cout << "========== Arithmetic Operators ==========" << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "b / c: " << b / c << std::endl;
	std::cout << "a / z: " << a / z << std::endl;
    std::cout << std::endl;

    std::cout << "========== Other Operators ==========" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a:" << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a:" << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
    std::cout << std::endl;

    std::cout << "========== Static Member Functions Overloads ==========" << std::endl;
	std::cout << "max(a,b): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a,b): " << Fixed::min( a, b ) << std::endl;
	std::cout << "max(a,c): " << Fixed::max( a, c ) << std::endl;
	std::cout << "min(a,c): " << Fixed::min( a, c ) << std::endl;
    std::cout << std::endl;

	return 0;
}