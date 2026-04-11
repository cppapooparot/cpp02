#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed() : number_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->number_value = other.number_value;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    number_value = value << fractional_bits; //the same as if we do value * 256
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    number_value = static_cast<int>(roundf(value * (1 << fractional_bits)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->number_value = other.number_value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called"<< std::endl;
}

int Fixed::getRawBits() const
{   
    std::cout << "getRawBits member function called" << std::endl;
    return this->number_value;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->number_value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(number_value) / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return number_value >>fractional_bits;
}

std::ostream& operator<<(std::ostream&os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
