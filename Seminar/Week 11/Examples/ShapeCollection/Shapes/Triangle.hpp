#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

#include "Shape.hpp"

class Triangle : public Shape{

public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	double GetArea() const override;
	double GetPer() const override;
	bool IsPointIn(int x, int y) const override;
	Shape *Clone() const override;

private:
	static constexpr double EPSILON = 0.00001;

};

#endif