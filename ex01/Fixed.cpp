#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointNum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNum = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNum = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixedPointNum = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
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
