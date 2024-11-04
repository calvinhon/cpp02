#include <iostream>

class   Fixed {

public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& src);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private:
    int                 _fixedPointNum;
    static const int    _fractionalBits;

};