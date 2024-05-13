#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP

#include "Parallelogram.hpp"

class Rectangle : public Parallelogram
{
    public:
        Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
        
        double GetArea() const;
};

#endif
