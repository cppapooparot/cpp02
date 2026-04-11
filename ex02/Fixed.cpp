#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>
#include <stdexcept>

Fixed::Fixed() : number_value(0) {}

Fixed::Fixed(const Fixed& other) {this->number_value = other.number_value;}

Fixed::Fixed(const int value) {number_value = value << fractional_bits; }

Fixed::Fixed(const float value) {number_value = static_cast<int>(roundf(value * (1 << fractional_bits)));}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this == &other)
        return *this;
    this->number_value = other.number_value;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {return this->number_value;}

void Fixed::setRawBits(int const raw) {this->number_value = raw;}

float Fixed::toFloat(void) const {return static_cast<float>(number_value) / (1 << fractional_bits);}

int Fixed::toInt(void) const {return number_value >>fractional_bits;}

std::ostream& operator<<(std::ostream&os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const {return number_value > other.number_value;}
bool Fixed::operator<(const Fixed& other) const {return number_value < other.number_value;}
bool Fixed::operator>=(const Fixed& other) const {return number_value >= other.number_value;}
bool Fixed::operator<=(const Fixed& other) const {return number_value <= other.number_value;}
bool Fixed::operator==(const Fixed& other) const {return number_value ==other.number_value;}

Fixed Fixed::operator+(const Fixed&other)
{
    Fixed ret;
    ret.setRawBits(this->number_value + other.number_value);
    return ret;
}

Fixed Fixed::operator-(const Fixed&other)
{
    Fixed ret;
    ret.setRawBits(this->number_value - other.number_value);
    return ret;
}

Fixed Fixed::operator*(const Fixed&other)
{
    Fixed ret;
    long long a = this->number_value;
    long long b = other.number_value;
    long long raw = (a * b) >> fractional_bits;
    ret.setRawBits(raw);
    return ret;
}

Fixed Fixed::operator/(const Fixed&other)
{
    if (other.number_value == 0)
        throw std::runtime_error("Fixed: division by zero");

    Fixed ret;
    long long a = this->number_value;
    long long b = other.number_value;
    long long raw = (a << fractional_bits) / b;
    ret.setRawBits(static_cast<int>(raw));
    return ret;
}

Fixed& Fixed::operator++()
{
    ++number_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    ++number_value;
    return ret;
}

Fixed& Fixed::operator--()
{
    --number_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    --number_value;
    return ret;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {return (a < b) ? a : b;}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {return (a < b) ? a : b;}

Fixed& Fixed::max(Fixed& a, Fixed& b) {return (a > b) ? a : b;}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {return (a > b) ? a : b;}
