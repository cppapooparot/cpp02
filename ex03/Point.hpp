#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
        Point& operator=(const Point& other); //x, y are const so we can't have = operator
    public:
        Point();
        Point(const Fixed& a, const Fixed& b);
        Point(const Point& other);
        Fixed getX() const;
        Fixed getY() const;
        ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif