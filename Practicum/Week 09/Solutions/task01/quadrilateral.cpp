#include "quadrilateral.h"
#include "triangle.h"

// Quadrilateral::Quadrilateral(){}

Quadrilateral::Quadrilateral(const Point& A, const Point& B, const Point& C, const Point& D)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}
double Quadrilateral::GetArea()
{
    Triangle ABC(A,B,C);
    Triangle ADC(A,D,C);

    return ABC.GetArea() + ADC.GetArea();
}
double Quadrilateral::GetPerimeter()
{
    return A.DistanceTo(B) + B.DistanceTo(C) + C.DistanceTo(D) + A.DistanceTo(D);
}
void Quadrilateral::Print(std::ostream& os)
{
    os << "A:"; A.Print(os);
    os << "B:"; B.Print(os);
    os << "C:"; C.Print(os);
    os << "D:"; D.Print(os);
}
Quadrilateral::~Quadrilateral(){}