#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "Shape.h"

class Circle : public Shape{

public:
	Circle(int x, int y, double radius);

	double GetArea() const override;
	double GetPer() const override; 
	bool IsPointIn(int x, int y) const override;

private:
	double radius;

};

#endif