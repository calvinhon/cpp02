#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNum(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	// std::cout << "Int constructor called" << std::endl;
    int max_value = (1 << (sizeof(_fixedPointNum) * 8 - _fractionalBits - 1)) - 1;
    int min_value = -(1 << (sizeof(_fixedPointNum) * 8 - _fractionalBits - 1));

    if (num > max_value) {
        _fixedPointNum = max_value << _fractionalBits;
    }
    else if (num < min_value) {
        _fixedPointNum = min_value << _fractionalBits;
    }
    else {
        _fixedPointNum = num << _fractionalBits;
    }
}

Fixed::Fixed(const float num) {
	// std::cout << "Float constructor called" << std::endl;
    int max_value = (1 << (sizeof(_fixedPointNum) * 8 - _fractionalBits - 1)) - 1;
    int min_value = -(1 << (sizeof(_fixedPointNum) * 8 - _fractionalBits - 1));

    if (num > max_value) {
        _fixedPointNum = roundf(max_value * (1 << _fractionalBits));
    }
    else if (num < min_value) {
        _fixedPointNum = roundf(min_value * (1 << _fractionalBits));
    }
    else {
        _fixedPointNum = roundf(num * (1 << _fractionalBits));
    }
}

Fixed::Fixed(const Fixed& src) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixedPointNum = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return _fixedPointNum;
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointNum = raw;
}

float	Fixed::toFloat(void) const {
	float	num = float(_fixedPointNum) / (1 << _fractionalBits);
	return num;
}

int		Fixed::toInt(void) const {
	int	num = _fixedPointNum >> _fractionalBits;
	return num;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (!other.toFloat()) {
        std::cout << "Undefined result due to division by ";
        return Fixed(0);
    }
    else
        return Fixed(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++() {
    this->_fixedPointNum++;
    return *this;
}

Fixed	Fixed::operator++(int) {
    Fixed   temp(this->toFloat());
    
    this->_fixedPointNum++;
    return temp;
}

Fixed&	Fixed::operator--() {
    this->_fixedPointNum--;
    return *this;
}

Fixed	Fixed::operator--(int) {
    Fixed   temp(this->toFloat());

    this->_fixedPointNum--;
    return temp;
}

const Fixed&	Fixed::min(Fixed& x, Fixed& y) {
    return x.toFloat() < y.toFloat() ? x : y;
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y) {
    return x.toFloat() < y.toFloat() ? x : y;
}

const Fixed&	Fixed::max(Fixed& x, Fixed& y) {
    return x.toFloat() > y.toFloat() ? x : y;
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y) {
    return x.toFloat() > y.toFloat() ? x : y;
}
