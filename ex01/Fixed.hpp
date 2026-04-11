#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
class Fixed
{
    private:
        int number_value;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const Fixed& other);
        Fixed(const float value);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 