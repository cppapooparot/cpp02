#include <iostream>
#include <cstdlib>
#include "Point.hpp"

static int g_failures = 0;

static void expect(bool condition, const char* msg)
{
    if (!condition)
    {
        std::cerr << "[FAIL] " << msg << std::endl;
        ++g_failures;
    }
    else
    {
        std::cout << "[OK]   " << msg << std::endl;
    }
}

int main()
{
    const Point a(Fixed(0), Fixed(0));
    const Point b(Fixed(10), Fixed(0));
    const Point c(Fixed(0), Fixed(10));

    // Clearly inside
    expect(bsp(a, b, c, Point(Fixed(1), Fixed(1))) == true, "point (1,1) is inside");

    // Outside
    expect(bsp(a, b, c, Point(Fixed(10), Fixed(10))) == false, "point (10,10) is outside");
    expect(bsp(a, b, c, Point(Fixed(-1), Fixed(1))) == false, "point (-1,1) is outside");

    // On vertices (should be outside for 'strictly inside' BSP in module 02)
    expect(bsp(a, b, c, a) == false, "point at vertex a is outside");
    expect(bsp(a, b, c, b) == false, "point at vertex b is outside");
    expect(bsp(a, b, c, c) == false, "point at vertex c is outside");

    // On edges (should be outside)
    expect(bsp(a, b, c, Point(Fixed(5), Fixed(0))) == false, "point on edge ab is outside");
    expect(bsp(a, b, c, Point(Fixed(0), Fixed(5))) == false, "point on edge ac is outside");
    expect(bsp(a, b, c, Point(Fixed(5), Fixed(5))) == false, "point on edge bc is outside");

    // Degenerate triangle (area 0) -> should be false
    const Point d1(Fixed(0), Fixed(0));
    const Point d2(Fixed(5), Fixed(5));
    const Point d3(Fixed(10), Fixed(10));
    expect(bsp(d1, d2, d3, Point(Fixed(1), Fixed(1))) == false, "degenerate triangle returns false");

    if (g_failures == 0)
    {
        std::cout << "All bsp tests passed." << std::endl;
        return 0;
    }
    std::cerr << g_failures << " bsp test(s) failed." << std::endl;
    return 1;
}