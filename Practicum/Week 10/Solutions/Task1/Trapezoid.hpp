#ifndef __TRAPEZOID_HPP
#define __TRAPEZOID_HPP

#include "Quadrilateral.hpp"

class Trapezoid : public Quadrilateral
{
    public:
        Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        Trapezoid* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetArea() const override;
        void Print(std::ostream& os = std::cout) const override;
};

#endif
