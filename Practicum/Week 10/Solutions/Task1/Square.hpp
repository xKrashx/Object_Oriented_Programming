#ifndef __SQUARE_HPP
#define __SQUARE_HPP

#include "Rectangle.hpp"
#include "Rhombus.hpp"

class Square : public Rectangle, public Rhombus
{
    public:
        Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        Square* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetPerimeter() const override;
        double GetArea() const override;
        
        void Print(std::ostream& os = std::cout) const override;
};

#endif
