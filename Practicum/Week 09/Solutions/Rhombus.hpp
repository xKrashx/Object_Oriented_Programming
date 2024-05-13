#ifndef __RHOMBUS_HPP
#define __RHOMBUS_HPP

#include "Parallelogram.hpp"

class Rhombus : public Parallelogram
{
    public:
        Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        double GetPerimeter() const;
        double GetArea() const;
        
        void Print(std::ostream& os = std::cout) const;
};

#endif
