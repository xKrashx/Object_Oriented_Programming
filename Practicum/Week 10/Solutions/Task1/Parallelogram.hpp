#ifndef __PARALLELOGRAM_HPP
#define __PARALLELOGRAM_HPP

#include "Quadrilateral.hpp"

class Parallelogram : public Quadrilateral
{
    public:
        Parallelogram(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        Parallelogram* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetPerimeter() const override;
        double GetArea() const override;

        void Print(std::ostream& os = std::cout) const override;
};

#endif
