#include "Square.hpp"

#include <cmath>
#include <stdexcept>
#include <new>

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : Parallelogram(p1, p2, p3, p4), Rectangle(p1, p2, p3, p4), Rhombus(p1, p2, p3, p4)
{
    // Квадратът е успоредник с равни съседни страни и четирите му ъгъла са прави.
    
    if(!(std::abs(GetP1().DistanceTo(GetP2()) - GetP2().DistanceTo(GetP3())) < EPS) || !(std::abs(GetP1().GetX() - GetP4().GetX()) < EPS))
    {
        throw std::invalid_argument("The square does not exist!");
    }
}

Square* Square::Clone() const 
{ 
    return new Square(*this); 
}

double Square::GetPerimeter() const
{
    return  4 * GetP1().DistanceTo(GetP2());
}

double Square::GetArea() const
{
    double a = GetP1().DistanceTo(GetP2());
    return a * a;
}

void Square::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;
    
    Quadrilateral::Print(os);
    os << std::endl;
    os << "a = " << GetP1().DistanceTo(GetP2()) << std::endl;
}
