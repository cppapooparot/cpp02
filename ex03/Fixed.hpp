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

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        Fixed operator+(const Fixed&other);
        Fixed operator-(const Fixed&other);
        Fixed operator*(const Fixed&other);
        Fixed operator/(const Fixed&other);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};


std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 