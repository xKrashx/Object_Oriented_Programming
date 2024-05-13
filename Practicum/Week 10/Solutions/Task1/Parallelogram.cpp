#include "Parallelogram.hpp"

#include <cmath>
#include <stdexcept>
#include <new>

Parallelogram::Parallelogram(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : Quadrilateral(p1, p2, p3, p4)
{
    // Успоредникът е четириъгълник, срещуположните страни на който са две по две успоредни и равни.
    // Т.е. е достатъчно да проверим, че две от тях да успоредни на оста ОХ и страните са две по две равни.

    double a = GetP1().DistanceTo(GetP2()), b = GetP2().DistanceTo(GetP3()), c = GetP3().DistanceTo(GetP4()), d = GetP1().DistanceTo(GetP4());

    if(!(std::abs(GetP1().GetY() - GetP2().GetY()) < EPS) || 
       !(std::abs(GetP3().GetY() - GetP4().GetY()) < EPS) || std::abs(GetP1().GetY() - GetP4().GetY()) < EPS ||  // успоредност на две от страните с оста ОХ
       !(std::abs(a - c) < EPS) || !(std::abs(b - d) < EPS))  // страните да са две по две равни
    {
        throw std::invalid_argument("The parallelogram does not exist!");
    }
}

Parallelogram* Parallelogram::Clone() const 
{ 
    return new Parallelogram(*this); 
}

double Parallelogram::GetPerimeter() const
{
    return  2 * (GetP1().DistanceTo(GetP2()) + GetP2().DistanceTo(GetP3()));
}

double Parallelogram::GetArea() const
{
    double a  = GetP1().DistanceTo(GetP2()),
           ha = GetP3().DistanceTo(Point(GetP3().GetX(), GetP1().GetY()));

    return a * ha;
}

void Parallelogram::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;
    
    Quadrilateral::Print(os);
    os << std::endl;
    os << "a = " << GetP1().DistanceTo(GetP2()) << ", b = " << GetP2().DistanceTo(GetP3()) << std::endl;
}
