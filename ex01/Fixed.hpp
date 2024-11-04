#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& src);
	~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
    int                 _fixedPointNum;
    static const int    _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif