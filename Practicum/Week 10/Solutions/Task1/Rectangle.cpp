#include "Rectangle.hpp"

#include <cmath>
#include <stdexcept>
#include <new>

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : Parallelogram(p1, p2, p3, p4)
{
    // Правоъгълникът се дефинира като успоредник с прав ъгъл.

    if(!(std::abs(GetP1().GetX() - GetP4().GetX()) < EPS))
    {
        throw std::invalid_argument("The rectangle does not exist!");
    }
}

Rectangle* Rectangle::Clone() const 
{ 
    return new Rectangle(*this); 
}

double Rectangle::GetArea() const
{
    double a = GetP1().DistanceTo(GetP2()), b = GetP2().DistanceTo(GetP3());
    return a * b;
}
