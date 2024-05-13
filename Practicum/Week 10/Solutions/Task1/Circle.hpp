#ifndef __CIRCLE_HPP
#define __CIRCLE_HPP

#include "Point.hpp"
#include "Figure.hpp"

class Circle : public Figure
{
    public:
        Circle(const Point& center, double radius);

        Circle* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetPerimeter() const override;
        double GetArea() const override;
        
        void Print(std::ostream& os = std::cout) const override;

    private:
        Point center;
        double radius;

        static const double PI; 
};

#endif
