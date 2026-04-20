#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed& a, const Fixed& b) : x(a), y(b) {}

Point::Point(const Point& other): x(other.x), y(other.y) {}

Point::~Point() {}

Fixed Point::getX() const {return x;}

Fixed Point::getY() const {return y;}

static float area(Point const& a, Point const& b, Point const& c)
{
    float x1 = a.getX().toFloat();
    float y1 = a.getY().toFloat();
    float x2 = b.getX().toFloat();
    float y2 = b.getY().toFloat();
    float x3 = c.getX().toFloat();
    float y3 = c.getY().toFloat();

    float ar = (x1 * (y2 - y3) +
                x2 * (y3 - y1) +
                x3 * (y1 - y2)) / 2.0f;

    return std::fabs(ar);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float A  = area(a, b, c);
    float A1 = area(point, b, c);
    float A2 = area(a, point, c);
    float A3 = area(a, b, point);

    const float eps = 1e-6f;

    if (A < eps)
        return false;

    if (A1 < eps || A2 < eps || A3 < eps)
        return false;

    return std::fabs((A1 + A2 + A3) - A) < eps;
}