#include "Circle.h"

const double PI = 3.1415;

Circle::Circle(int x, int y, double radius): Shape(1), radius(radius){
	SetPoint(0, x, y);
}

double Circle::GetArea() const{
	return PI * radius * radius;
}

double Circle::GetPer() const{
	return 2 * PI * radius;
}

bool Circle::IsPointIn(int x, int y) const{
	return GetPointAtIndex(0).GetDistance(Shape::Point(x, y)) <= radius;
}
