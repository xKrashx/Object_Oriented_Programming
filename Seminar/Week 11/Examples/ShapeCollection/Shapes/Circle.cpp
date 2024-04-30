#include "Circle.hpp"

Circle::Circle(int x, int y, double radius): Shape(1), m_Radius(radius){
	SetPoint(0, x, y);
}

double Circle::GetArea() const{
	return PI * m_Radius * m_Radius;
}

double Circle::GetPer() const{
	return 2 * PI * m_Radius;
}

bool Circle::IsPointIn(int x, int y) const{
	return GetPointAtIndex(0).GetDistance(Shape::Point(x, y)) <= m_Radius;
}

Shape *Circle::Clone() const{
	return new Circle(*this);
}