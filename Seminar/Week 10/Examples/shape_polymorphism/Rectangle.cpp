#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3): Shape(4){

	SetPoint(0, x1, y1);
	SetPoint(1, x1, y3);
	SetPoint(2, x3, y3);
	SetPoint(3, x3, y1);

}

double Rectangle::GetArea() const{

	Shape::Point p0 = GetPointAtIndex(0);
	Shape::Point p1 = GetPointAtIndex(1);
	Shape::Point p3 = GetPointAtIndex(3);

	return p0.GetDistance(p1) * p0.GetDistance(p3);

}

double Rectangle::GetPer() const{

	Shape::Point p0 = GetPointAtIndex(0);
	Shape::Point p1 = GetPointAtIndex(1);
	Shape::Point p3 = GetPointAtIndex(3);

	return 2 * (p0.GetDistance(p1) + p0.GetDistance(p3));

}

bool Rectangle::IsPointIn(int x, int y) const{

	Shape::Point p(x, y);
	return p.x >= GetPointAtIndex(0).x && p.y >= GetPointAtIndex(1).x &&
		p.y <= GetPointAtIndex(0).y && p.y >= GetPointAtIndex(2).y;

}
