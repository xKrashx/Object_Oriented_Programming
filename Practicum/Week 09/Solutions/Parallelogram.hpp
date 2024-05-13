#ifndef __PARALLELOGRAM_HPP
#define __PARALLELOGRAM_HPP

#include "Quadrilateral.hpp"

class Parallelogram : public Quadrilateral
{
    public:
        Parallelogram(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        double GetPerimeter() const;
        double GetArea() const;

        void Print(std::ostream& os = std::cout) const;
};

#endif
