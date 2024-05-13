#ifndef __RHOMBUS_HPP
#define __RHOMBUS_HPP

#include "Parallelogram.hpp"

class Rhombus : virtual public Parallelogram
{
    public:
        Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        Rhombus* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetPerimeter() const override;
        double GetArea() const override;
        
        void Print(std::ostream& os = std::cout) const override;
};

#endif
