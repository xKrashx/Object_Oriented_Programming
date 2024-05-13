#ifndef __SQUARE_HPP
#define __SQUARE_HPP

#include "Parallelogram.hpp"

class Square : public Parallelogram
{
    public:
        Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        double GetPerimeter() const;
        double GetArea() const;
        
        void Print(std::ostream& os = std::cout) const;
};

#endif
