#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "Shape.hpp"

class Circle : public Shape{

public:
	Circle(int x, int y, double radius);

	double GetArea() const override;
	double GetPer() const override; 
	bool IsPointIn(int x, int y) const override;
	Shape *Clone() const override;

private:
	static constexpr double PI = 3.1415;
	double m_Radius;

};

#endif