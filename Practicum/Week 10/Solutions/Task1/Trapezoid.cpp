#include "Trapezoid.hpp"

#include <cmath>
#include <stdexcept>
#include <new>

Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : Quadrilateral(p1, p2, p3, p4)
{
    // Трапецът е четириъгълник, в който една двойка срещуположни страни са успоредни.
    // Ще приемем, че горната и долната основа са успоредни на оста ОХ, т.е. точките от долната основа - p1 и p2, 
    // както и точките от горната основа - p3 и p4, трябва да имат еднаква y-координата.
        
    if(!(std::abs(GetP1().GetY() - GetP2().GetY()) < EPS) || !(std::abs(GetP3().GetY() - GetP4().GetY()) < EPS) || 
       std::abs(GetP1().GetY() - GetP4().GetY()) < EPS)
    {
        throw std::invalid_argument("The trapezoid does not exist!");
    }
}

Trapezoid* Trapezoid::Clone() const 
{ 
    return new Trapezoid(*this); 
}

double Trapezoid::GetArea() const
{
    double a = GetP1().DistanceTo(GetP2()), b = GetP4().DistanceTo(GetP3()),
           h = GetP4().DistanceTo(Point(GetP4().GetX(), GetP1().GetY()));

    return 0.5 * (a + b) * h;
}

void Trapezoid::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;
    
    Quadrilateral::Print(os);
    os << std::endl;
    os << "a = " << GetP1().DistanceTo(GetP2()) << ", b = " << GetP4().DistanceTo(GetP3()) << std::endl;
}
