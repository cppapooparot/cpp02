#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : number_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->number_value = other.number_value;
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