#ifndef __TRIANGLE_HPP
#define __TRIANGLE_HPP

#include "Point.hpp"
#include "Figure.hpp"

class Triangle : public Figure
{
    public:
        Triangle(const Point& p1, const Point& p2, const Point& p3);

        Triangle* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetPerimeter() const override;
        double GetArea() const override;
        
        void Print(std::ostream& os = std::cout) const override;

    private:
        Point p1, p2, p3;
        double a, b, c;
};

#endif
