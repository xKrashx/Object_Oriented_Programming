#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3): Shape(3){

	SetPoint(0, x1, y1);
	SetPoint(1, x2, y2);
	SetPoint(2, x3, y3);

}

double Triangle::GetArea() const{

	Shape::Point p1 = GetPointAtIndex(0);
	Shape::Point p2 = GetPointAtIndex(1);
	Shape::Point p3 = GetPointAtIndex(2);

	return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2.00;

}

double Triangle::GetPer() const{

	Shape::Point p1 = GetPointAtIndex(0);
	Shape::Point p2 = GetPointAtIndex(1);
	Shape::Point p3 = GetPointAtIndex(2);

	return p1.GetDistance(p2) + p2.GetDistance(p3) + p3.GetDistance(p1);

}

bool Triangle::IsPointIn(int x, int y) const{

	Shape::Point p(x, y);
	Triangle t1(GetPointAtIndex(0).x, GetPointAtIndex(0).y, GetPointAtIndex(1).x, GetPointAtIndex(1).y, p.x, p.y);
	Triangle t2(GetPointAtIndex(2).x, GetPointAtIndex(2).y, GetPointAtIndex(1).x, GetPointAtIndex(1).y, p.x, p.y);
	Triangle t3(GetPointAtIndex(2).x, GetPointAtIndex(2).y, GetPointAtIndex(0).x, GetPointAtIndex(0).y, p.x, p.y);

	return abs(t1.GetArea() + t2.GetArea() + t3.GetArea() - GetArea()) <= EPSILON;

}

Shape *Triangle::Clone() const{
	return new Triangle(*this);
}