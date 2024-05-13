#include "Rhombus.hpp"

#include <stdexcept>
#include <new>

Rhombus::Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : Parallelogram(p1, p2, p3, p4)
{
    // Ромбът е успоредник с равни съседни страни. Т.е. трябва да проверим само дали съседните страни са равни.

    if(!(std::abs(GetP1().DistanceTo(GetP2()) - GetP2().DistanceTo(GetP3())) < EPS))
    {
        throw std::invalid_argument("The rhombus does not exist!");
    }
}

Rhombus* Rhombus::Clone() const 
{ 
    return new Rhombus(*this); 
}

double Rhombus::GetPerimeter() const
{
    return  4 * GetP1().DistanceTo(GetP2());
}

double Rhombus::GetArea() const
{
    double a = GetP1().DistanceTo(GetP2()),
           h = GetP3().DistanceTo(Point(GetP3().GetX(), GetP1().GetY()));

    return a * h;
}

void Rhombus::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;

    Quadrilateral::Print(os);
    os << std::endl;
    os << "a = " << GetP1().DistanceTo(GetP2()) << std::endl;
}
