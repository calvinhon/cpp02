#include "Fixed.hpp"

const int   Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointNum(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& src) {
    std::cout << "Copy assignment operatore called" << std::endl;
    if (this != &other)
        return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
