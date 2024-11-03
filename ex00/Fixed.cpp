#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNum(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed& operator=(const Fixed& other) {
    if (this != &other)
        return *this;
}
